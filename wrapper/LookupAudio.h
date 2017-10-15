/**
 * Header File for the LookupAudio.c
 * Only need to declare @function lookup_audio here,
 * since it's the only one called from the module.
 */

#ifndef LOOKUP_AUDIO_H
#define LOOKUP_AUDIO_H

char* lookup_audio(const char* client_id,
				 const char* client_id_tag,
				 const char* license_path,
				 const char* file_path,
				 const char* result_str);

#endif /* LOOKUP_AUDIO_H */
