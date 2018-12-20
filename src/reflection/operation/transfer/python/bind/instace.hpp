#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_instance
#define reflection_operation_transfer_python_bind_instance

// ::reflection::operation::transfer::python::bind::instance_class

#include "../../../factory.hpp"

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

          //template
          // <
          //   typename         data_name = std::string
          //   typename         string_name = std::string
          // >
          class instance_class
           {
            public:
              typedef std::size_t   size_type;
              typedef std::string string_type, identifier_type;

              //typedef ::reflection::property::pure_class  property_type;
              //typedef ::reflection::property::pure_class  property_type;

              typedef ::reflection::operation::transfer::factory_class<identifier_type>         factory_type;

              typedef int property_type;
              typedef int* property_pointer_type;

              typedef struct data_struct
               {
                PyObject_HEAD;

                data_struct(){}
                ~data_struct(){ delete this->m_this; }
                size_type m_count            =0;
                identifier_type m_identifier;
                factory_type *m_factory     = nullptr;
                property_pointer_type m_this       = nullptr;
               } data_type;

              data_type m_data; //!< one and only data

              static void      forPython_dealloc(instance_class *self)
               {
                self->m_data.~data_struct();
                Py_TYPE(self)->tp_free((PyObject *)self);
               }

              static PyObject *forPython_new( PyTypeObject *type, PyObject *args, PyObject *kwds )
               {
                instance_class *self;
                self = reinterpret_cast<instance_class *>( type->tp_alloc( type, 0 ) );
                if (self == NULL)
                 {
                  return reinterpret_cast<PyObject *>( self );
                 }

                new ((void*)(&self->m_data)) data_struct;
                if( nullptr != self->m_data.m_factory )
                 {
                  self->m_data.m_this = new int{123}; 
                  //self->m_data.m_this = self->m_data.m_factory->create( self->m_data.m_identifier );
                 }


                return reinterpret_cast<PyObject *>( self );
               }

              static int       forPython_init( instance_class *self, PyObject *args, PyObject *kwds)
               {
                self->m_data.m_count = 0;
                //*(self->m_data.m_this) = 456;
                return 0;
               }

           };

         }
       }
     }
   }
 }

#endif
#endif




