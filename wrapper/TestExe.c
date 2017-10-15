#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LookupAudio.h"

int main()
{
    char* client_id     = NULL;
	char* client_id_tag = NULL;
	char* license_path  = NULL;
	char* file_path     = NULL;
	char* result_str    = NULL;
    char* resp;

    resp = lookup_audio(client_id, client_id_tag, license_path, file_path, result_str);

    printf("%s %s %s\n", file_path, result_str, resp)

    return 0;
}