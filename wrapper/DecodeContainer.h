
#ifndef DECODE_CONTAINER_H
#define DECODE_CONTAINER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/frame.h>
#include <libavutil/mem.h>
#include <libavutil/avassert.h>
#include <libavutil/timestamp.h>


typedef struct {

//	int						sample_position;
	int						data_size;
	int 					audio_stream_idx;
	const char* 			filename;
	uint8_t 				data[6144];
	AVPacket 				pkt;
	AVFrame*				frame;
	AVStream* 				audio_stream;
	AVFormatContext* 		fmt_ctx;
	AVCodecContext* 		audio_dec_ctx;
	AVCodecParserContext* 	parser;

} DecodeContainer;

void decode(AVCodecContext *dec_ctx, AVPacket *pkt, AVFrame *frame,
			uint8_t* outdata, int* read_size);

int open_codec_context(int *stream_idx,
					   AVCodecContext **dec_ctx,
					   AVFormatContext *fmt_ctx,
					   enum AVMediaType type,
					   const char* src_filename);

int init_decode_container(DecodeContainer* ctn, const char* filename);

void release_decode_container(DecodeContainer* ctn);

int get_next_chunk(DecodeContainer* ctn);


#endif /* DECODE_CONTAINER_H */