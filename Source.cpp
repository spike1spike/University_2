#include <Python.h>
#include <ctime>

static PyObject* minList_minel(PyObject* self, PyObject* args) {
    PyObject* listObj;

    if (!PyArg_ParseTuple(args, "O", &listObj))
        return NULL;

    clock_t start_time = clock();

    long length = PyList_Size(listObj);
    PyObject* temp = PyList_GetItem(listObj, 0);
    long min_el = PyLong_AsLong(temp);

    for (long i = 1; i < length; i++) {
        PyObject* temp = PyList_GetItem(listObj, i);
        long elem = PyLong_AsLong(temp);   // <-- Python 3 вариант
        if (elem < min_el) {
            min_el = elem;
        }
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    PyObject* result = PyTuple_New(2);
    PyTuple_SET_ITEM(result, 0, PyLong_FromLong(min_el));
    PyTuple_SET_ITEM(result, 1, PyFloat_FromDouble(time_taken));

    return result;   // <-- Python 3 вариант
}

static char minList_docs[] =
"minel(): find smallest element of the list\n";

static PyMethodDef minList_funcs[] = {
    {"minel", minList_minel, METH_VARARGS, minList_docs},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef minList_module = {
    PyModuleDef_HEAD_INIT,
    "minList",      // имя модуля
    "Find smallest element of the list",  // документация
    -1,
    minList_funcs
};

PyMODINIT_FUNC PyInit_minList(void) {   // <-- имя строго PyInit_<module>
    return PyModule_Create(&minList_module);
}