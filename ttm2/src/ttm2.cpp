
#include "ttm2.hpp"
#include "RynTypes.hpp"


        Real_t ttm2___ttm2f_mod_MOD_ttm2f(
            FlatCoordinates coords,
            Names atoms,
            ExtraBools extra_bools,
            ExtraInts extra_ints,
            ExtraFloats extra_floats
            ) {
        
            // Load extra args (if necessary)
            
            int nwaters = extra_ints[0];
int imodel = extra_ints[1];
            
            
            // Get data as raw array
            RawWalkerBuffer raw_coords = coords.data();
        
            
            double derivs[nwaters*3*3]; // allocate space for the derivatives
            
            
            Real_t energy = -100000;
            __ttm2f_mod_MOD_ttm2f(&nwaters,raw_coords,derivs,&energy,&imodel);
            return energy;
            ;
        }
        
        static PyObject* ttm2___ttm2f_mod_MOD_ttm2fWrapper = PyCapsule_New((void *)ttm2___ttm2f_mod_MOD_ttm2f, "_potential", NULL);
        

bool _AttachCapsuleToModule(PyObject* module, PyObject* capsule, const char* name) {
    bool i_did_good = (PyModule_AddObject(module, name, capsule) == 0);
    if (!i_did_good) {
        Py_XDECREF(capsule);
        Py_DECREF(module);
    }

    return i_did_good;
}

static PyMethodDef ttm2Methods[] = {
        {NULL, NULL, 0, NULL}
};

// TODO: ADD IN SOMETHING THAT LETS US GET THE ARGUMENT NAMES DIRECTLY FROM THE LIB

#if PY_MAJOR_VERSION > 2

const char ttm2_doc[] = "ttm2 provides a potential";
static struct PyModuleDef ttm2Module = {
    PyModuleDef_HEAD_INIT,
    "ttm2",   /* name of module */
    ttm2_doc, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    ttm2Methods
};

PyMODINIT_FUNC PyInit_ttm2(void)
{
    PyObject *m;
    m = PyModule_Create(&ttm2Module);
    if (m == NULL) {
        return NULL;
    }

    if (!_AttachCapsuleToModule(m, ttm2___ttm2f_mod_MOD_ttm2fWrapper, "_potential")) { return NULL; }

    return m;
}

#else

PyMODINIT_FUNC initttm2(void)
{
    PyObject *m;
    m = Py_InitModule("ttm2", ttm2Methods);
    if (m == NULL) {
    return NULL
    }

    _AttachCapsuleToModule(m, ttm2_PotentialWrapper);
}

#endif