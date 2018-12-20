
#include <Python.h>

#define MODULE_NAME_SYMBOLIC Spam
#define MODULE_NAME_STRING   #MODULE_NAME_SYMBOLIC

#define INIT_FUNCTION(module_name) init##module_name

void ( )
 {


 }

PyMODINIT_FUNC
INIT_FUNCTION(MODULE_NAME_SYMBOLIC)(void)
 {
  PyObject *m;

  m = Py_InitModule(MODULE_NAME_STRING, SpamMethods);
  if (m == NULL)
      return;

  SpamError = PyErr_NewException("spam.error", NULL, NULL);
  Py_INCREF( SpamError );
  PyModule_AddObject( m, "error", SpamError );
  return;
 }