//
// Created by dudeson on 20.09.17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/frame.h>
#include <libavutil/mem.h>
#include <libavutil/avassert.h>
#include <libavutil/timestamp.h>

#include "DecodeContainer.h"


int decode(AVCodecContext *dec_ctx, AVPacket *pkt, AVFrame *frame,
		   uint8_t* outdata, int* read_size)
{
	int i, ch;
	int ret, data_size;
	size_t shft;
	const int nr_skipping_frames = 5;

	/* send the packet with the compressed data to the decoder */
	ret = avcodec_send_packet(dec_ctx, pkt);
	if (ret < 0) {
		fprintf(stderr, "Error submitting the packet to the decoder (%d; %s)\n", ret, av_err2str(ret));
		return -1;
	}

	/* read all the output frames (in general there may be any number of them */
	while (ret >= 0) {
		ret = avcodec_receive_frame(dec_ctx, frame);
		if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
//			fprintf(stderr, "Error %s\n", av_err2str(ret));
			return 0;
		}
		else if (ret < 0) {
			fprintf(stderr, "Error during decoding\n");
			return -1;
		}

//		if (audio_frame_count % 100)
//			printf("audio_frame n:%d nb_samples:%d pts:%s\n",
//			   audio_frame_count, frame->nb_samples,
//			   av_ts2timestr(frame->pts, &dec_ctx->time_base));

		data_size = av_get_bytes_per_sample(dec_ctx->sample_fmt);
		if (data_size < 0) {
			/* This should not occur, checking just for paranoia */
			fprintf(stderr, "Failed to calculate data size\n");
			return -1;
		}

//		FILE * outfile;
//		outfile = fopen("test.bin","ab");
//		if (!outfile) {
//			fprintf(stderr, "Could not open destination file\n");
//			return;
//		}

//		printf("Writing output... frames %d, ch %d\n", frame->nb_samples, dec_ctx->channels);
		for (i = 0; i < frame->nb_samples; i++){
			for (ch = 0; ch < dec_ctx->channels; ch++) {
				shft = i*data_size*data_size + ch*data_size;
				memcpy(outdata + shft, frame->data[ch] + data_size * i, data_size);
//				fwrite(frame->data[ch] + data_size * i, 1, data_size, outfile);
			}
		}

//		fclose(outfile);

		*read_size = frame->nb_samples * dec_ctx->channels * data_size; // nr of bytes
	}
	return 0;
}

int open_codec_context(int *stream_idx,
					   AVCodecContext **dec_ctx,
					   AVFormatContext *fmt_ctx,
					   enum AVMediaType type,
					   const char* src_filename)
{
	int ret, stream_index;
	AVStream *st;
	AVCodec *dec = NULL;
	AVDictionary *opts = NULL;

	ret = av_find_best_stream(fmt_ctx, type, -1, -1, NULL, 0);
	if (ret < 0) {
		fprintf(stderr, "Could not find %s stream in input file '%s'\n",
				av_get_media_type_string(type), src_filename);
		return ret;
	} else {
		stream_index = ret;
		st = fmt_ctx->streams[stream_index];

		/* find decoder for the stream */
		dec = avcodec_find_decoder(st->codecpar->codec_id);
		if (!dec) {
			fprintf(stderr, "Failed to find %s codec\n",
					av_get_media_type_string(type));
			return AVERROR(EINVAL);
		}

		/* Allocate a codec context for the decoder */
		*dec_ctx = avcodec_alloc_context3(dec);
		if (!*dec_ctx) {
			fprintf(stderr, "Failed to allocate the %s codec context\n",
					av_get_media_type_string(type));
			return AVERROR(ENOMEM);
		}

		/* Copy codec parameters from input stream to output codec context */
		if ((ret = avcodec_parameters_to_context(*dec_ctx, st->codecpar)) < 0) {
			fprintf(stderr, "Failed to copy %s codec parameters to decoder context\n",
					av_get_media_type_string(type));
			return ret;
		}

		/* Init the decoders, with or without reference counting */
		av_dict_set(&opts, "refcounted_frames", /*refcount ? "1" :*/ "0", 0);
		if ((ret = avcodec_open2(*dec_ctx, dec, &opts)) < 0) {
			fprintf(stderr, "Failed to open %s codec\n",
					av_get_media_type_string(type));
			return ret;
		}
		*stream_idx = stream_index;
	}

	return 0;
}

int init_decode_container(DecodeContainer* ctn, const char* filename)
{
	ctn->filename 			= filename;
//	ctn->sample_position	= 0;
	ctn->data_size			= 0;
	ctn->audio_stream_idx 	= 0;
//	ctn->data				= {0};

	ctn->fmt_ctx 			= NULL;
	ctn->audio_dec_ctx		= NULL;
	ctn->parser 			= NULL;
	ctn->frame 				= NULL;
	ctn->audio_stream 		= NULL;

	av_register_all();

	/* open input file, and allocate format context */
	if (avformat_open_input(&(ctn->fmt_ctx), ctn->filename, NULL, NULL) < 0) {
		fprintf(stderr, "Could not open source file %s\n", ctn->filename);
		exit(1);
	}

	/* retrieve stream information */
	if (avformat_find_stream_info(ctn->fmt_ctx, NULL) < 0) {
		fprintf(stderr, "Could not find stream information\n");
		exit(1);
	}

	if (open_codec_context(&(ctn->audio_stream_idx), &(ctn->audio_dec_ctx), ctn->fmt_ctx, AVMEDIA_TYPE_AUDIO,ctn->filename) >= 0) {
		ctn->audio_stream = ctn->fmt_ctx->streams[ctn->audio_stream_idx];
	}

	av_init_packet(&(ctn->pkt));
	ctn->pkt.data = NULL;
	ctn->pkt.size = 0;


	return 0;
}

void release_decode_container(DecodeContainer* ctn)
{
	if (ctn)
	{
		avcodec_free_context(&(ctn->audio_dec_ctx));
		avformat_close_input(&(ctn->fmt_ctx));
		av_frame_free(&(ctn->frame));
	}
}

int get_next_chunk(DecodeContainer* ctn)
{
	if (!(ctn->frame = av_frame_alloc())) {
		fprintf(stderr, "Could not allocate audio frame\n");
		return -1;
	}

	/* read frames from the file */
	if (av_read_frame(ctn->fmt_ctx, &(ctn->pkt)) < 0) {
		return -1;
	}

//	printf("Reading packet %d at %d\t size %d\n",
//		   ctn->pkt.stream_index, ctn->pkt.pos, ctn->pkt.size);

	decode(ctn->audio_dec_ctx, &(ctn->pkt), ctn->frame,
		   ctn->data, &ctn->data_size);

	return ctn->data_size;
}
