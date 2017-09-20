/**
 * Wrapper of the C gnsdk lookup module for python
 *
 * Before using u have to set the library path (where the gnsdk and ffmpeg libs lay)
 * in your IDE or cmd, e.g.:
 *
 * 		$ export LD_LIBRARY_PATH=/usr/local/lib:/path/to/gnsdk/lib/linux_x86-64:$LD_LIBRARY_PATH
 *
 * python:
 * 		>>> import CGnsdkLookup
 * 		>>> res = CGnsdkLookup.lookup_audio(client_id,			\
 * 								  		client_id_tag,   		\
 * 								  		"/path/to/licence", 	\
 * 								  		"/path/to/audio.mp3") 	\
 * 		>>> res
 * 		>>> '{"artist": "Queen", "album": "A Night At The Opera", "track": "Bohemian Rhapsody"}'
 *
 * The result string can be converted to a dict via:
 *
 * 		>>> import ast
 * 		>>> ast.literal_eval(res)
 */


#include <stdio.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "LookupAudio.h"

static PyObject * lookup_audio_wrapper(PyObject * self, PyObject * args)
{
//	printf("Now in wrapper.\n");
	const char* client_id;
	const char* client_id_tag;
	const char* license_path;
	const char* file_path;
	char result[1024] = {0};

	// Parse input tuple
	if (!PyArg_ParseTuple(args, "ssss", &client_id, &client_id_tag, &license_path,&file_path))
		return NULL;


	lookup_audio(client_id,client_id_tag,license_path,file_path,result);

//	printf("FINISHED\n");

	return Py_BuildValue("s", result);
}

static PyMethodDef CGnsdkLookupMethods[] = {
		{ "lookup_audio", lookup_audio_wrapper, METH_VARARGS, "Lookup an audio file via the GNSDK library" },
		{ NULL, NULL, 0, NULL }
};

static struct PyModuleDef CGnsdkLookup = {
		PyModuleDef_HEAD_INIT,
		"CGnsdkLookup",   /* name of module */
		NULL, /* module documentation, may be NULL */
		-1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
		CGnsdkLookupMethods,
		NULL,
		NULL,
		NULL,
		NULL,
};

/* Initialize the module */
PyObject *PyInit_CGnsdkLookup(void)
{
	PyObject *module = PyModule_Create(&CGnsdkLookup);
	if (module == NULL)
		return NULL;

	/* Load `numpy` functionality. */
//	import_array();

	return module;
}
