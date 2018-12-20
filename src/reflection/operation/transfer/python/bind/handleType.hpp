#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_handleType_class
#define reflection_operation_transfer_python_bind_handleType_class

// ::reflection::operation::transfer::python::bind::handleType_class

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

          class handleType_class
           {
            public:
              handleType_class( )
               {
                memset( &this->m_native, 0, sizeof( PyTypeObject ) );
               }
             ~handleType_class( ){ }

            public:
              PyObject     const* getO()const{ return reinterpret_cast<PyObject const*>( &m_native ); }
              PyObject          * getO()     { return reinterpret_cast<PyObject      *>( &m_native ); }

              PyTypeObject const* getT()const{ return &m_native; }
              PyTypeObject      * getT()     { return &m_native; }

            private:
              PyTypeObject m_native;
           };

         }
       }
     }
   }
 }

#endif
#endif
