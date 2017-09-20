#include <stdio.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "LookupAudio.h"

/**
 * example python: CGnsdkLookup.lookup_audio("1312006557","9CE95C3EBC19CBA3C1F0C604EDA46464","/home/dudeson/Documents/gnsdk/LICENSE","/home/dudeson/Music/TEST/Queen - Bohemian Rhapsody (Official Video).mp3")
 * @param self
 * @param args
 * @return
 */

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
