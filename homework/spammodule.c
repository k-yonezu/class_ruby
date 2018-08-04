#include <Python.h>

//Cの方で作成してPythonで利用する関数はPyObjectを使う

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    return Py_BuildValue("i", sts);
}

// メソッドの定義
static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS, "Execute a shell command."},
	// 終了を示す
	{NULL, NULL, 0, NULL}
};

//モジュールの定義
static struct PyModuleDef spammodule = {
	PyModuleDef_HEAD_INIT,
	"spam",
	NULL,
	-1,
	SpamMethods
};

// メソッドの初期化
PyMODINIT_FUNC PyInit_spam(void) {
	return PyModule_Create(&spammodule);
}
