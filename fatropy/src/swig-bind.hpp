#pragma once
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <casadi/casadi.hpp>
#include <vector>
namespace fatropy
{
    namespace py = pybind11;
    struct PySwigObject
    {
        PyObject_HEAD void *ptr;
        const char *decr;
    };
    template <typename T>
    struct FromPySwig
    {
        static T *convert(const py::object &obj, const std::string &name)
        {
            // todo: figure out how this actually works, it is inspired by eigenpy
            PyObject *obj_ptr = obj.ptr();
            return convert(obj_ptr, name);
        }
        static T *convert(PyObject *obj_ptr, const std::string &name)
        {
            PyObject *this_ptr = PyObject_GetAttrString(obj_ptr, "this");
            PySwigObject *swig_obj = reinterpret_cast<PySwigObject *>(this_ptr);
            std::string py_name = reinterpret_cast<PySwigObject *>(obj_ptr)->ob_base.ob_type->tp_name;
            if (py_name != name)
                throw std::runtime_error("Could not convert of type " + py_name + " to " + name);
            if (this_ptr == nullptr)
                throw std::runtime_error("Could not convert to PySwigObject");
            auto ret = reinterpret_cast<T *>(swig_obj->ptr);
            return ret;
        }
    };
    void print_function_nametest(casadi::Function f)
    {
        std::cout << "Function pointer: ";
        std::cout << &f << std::endl;
        std::cout << "Function name: ";
        std::cout << f.name() << std::endl;
        std::cout << "number of inputs = " << f.n_in() << std::endl;
    };
}
namespace PYBIND11_NAMESPACE
{
    namespace detail
    {
        template <typename T>
        struct swig_type_caster
        {
        public:
            using type_cpp = typename T::type;
            // using name_cpp = T::name;
            PYBIND11_TYPE_CASTER(type_cpp, const_name(T::py_name));

            bool load(handle src, bool)
            {
                /* Extract PyObject from handle */
                PyObject *source = src.ptr();
                /* Try converting into a Python integer value */
                PyObject *tmp = source;
                if (!tmp)
                    return false;
                /* Now try to convert into a C++ int */
                // value.long_value = PyLong_AsLong(tmp);
                value = *fatropy::FromPySwig<type_cpp>::convert(source, T::py_name);
                Py_DECREF(tmp);
                /* Ensure return code was OK (to avoid out-of-range errors etc) */
                return !PyErr_Occurred();
                // return false;
            }

            static handle cast(type_cpp src, return_value_policy /* policy */, handle /* parent */)
            {
                return PyLong_FromLong(0);
            }
        };
        struct casadi_swig_wrap_type
        {
            typedef casadi::Function type;
            static constexpr char py_name[] = "Function";
        };

        template <>
        struct type_caster<casadi::Function> : public swig_type_caster<casadi_swig_wrap_type>
        {
        };

    } // namespace PYBIND11_NAMESPACE::detail
}
