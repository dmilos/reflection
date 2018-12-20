#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_handleObject
#define reflection_operation_transfer_python_bind_handleObject

// ::reflection::operation::transfer::python::bind::handleObject_class

#include "./instace.hpp"
#include "./interface.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace python
       {
        namespace bind
         {

          class handleObject_class
           {
            public:
              handleObject_class( ){ m_native = nullptr;  }
             ~handleObject_class( ){ if( nullptr!=m_native)Py_DECREF( m_native );  m_native = nullptr; }

            public:
              handleObject_class & operator=( handleObject_class const& that )
               {
                if( nullptr != m_native ){ Py_DECREF( m_native ); }
                m_native = const_cast<PyObject*>( that.get() );
                if( nullptr != m_native ){ Py_INCREF( m_native ); }
                return *this;
               }

            public:
              PyObject const* get()const{ return m_native; }
              PyObject      * get()     { return m_native; }
              PyObject * set( PyObject * native ){ if( nullptr != m_native){ Py_DECREF( m_native );} m_native = native; }
              PyObject * release(){ auto result = m_native; m_native = nullptr; return result; }
              void reset(){ if( nullptr != m_native){ Py_DECREF( m_native ); } m_native = nullptr; }

            private:
              PyObject * m_native;
           };

         }
       }
     }
   }
 }

#endif
#endif
