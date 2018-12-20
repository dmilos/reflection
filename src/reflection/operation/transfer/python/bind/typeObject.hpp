#ifdef Py_PYTHON_H     

#ifndef reflection_operation_transfer_python_bind_typeObject
#define reflection_operation_transfer_python_bind_typeObject

// ::reflection::operation::transfer::python::bind::typeObject_class

#include "./instace.hpp"
#include "./interface.hpp"
#include "./handleType.hpp"

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
          //   typename         string_name = std::string
          // >
          class typeObject_class
           {
            public:
              typedef std::size_t  size_type;
              typedef std::string string_type, identifier_type;

              typedef ::reflection::operation::transfer::python::bind::handleType_class handleType_type;

              typedef ::reflection::operation::transfer::python::bind::instance_class     instace_type;
              typedef ::reflection::operation::transfer::python::bind::interface_class  interface_type;

            public:
              explicit typeObject_class()
               {
               }

             public:
               handleType_type const& build_1st()const
                {
                 auto typeObject = m_handle.getT();
                 typeObject->tp_name    = m_identifier.data();
                 typeObject->tp_basicsize = sizeof( instace_type::data_type );
                 typeObject->tp_itemsize = sizeof( PyObject * );

                 m_interface.syncronize();

                 typeObject->tp_members = const_cast< PyMemberDef* >( m_interface.memberDefA().data() );
                 typeObject->tp_methods = const_cast< PyMethodDef* >( m_interface.methodDefA().data() );

                 typeObject->tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE;

                 typeObject->tp_init    = (initproc)instace_type::forPython_init;
                 typeObject->tp_dealloc = (destructor)instace_type::forPython_dealloc;
                 typeObject->tp_new     = instace_type::forPython_new;

                 typeObject->tp_doc = m_doc.data();
                 return this->handle();
                }

               handleType_type const& build_2nd()const
                {
                 auto typeObject = m_handle.getT();

                 if( 0 != m_superClass.size() ) 
                 {
                  //if( nullptr != typeObject->tp_base ) Py_DECREF( typeObject->tp_base );
                  typeObject->tp_base = const_cast<PyTypeObject *>( m_superClass.begin()->second->handle().getT() );
                  //if( nullptr != typeObject->tp_bases ) Py_DECREF( typeObject->tp_bases );
                  //typeObject->tp_bases = PyTuple_New( m_superClass.size() );
                  //if( nullptr != typeObject->tp_bases)
                  // {
                  //  size_type index=0;
                  //  for ( auto const& item: m_superClass ) 
                  //   {
                  //    PyObject *object = const_cast<PyObject *>( item.second->handle().getO() );
                  //    PyTuple_SetItem(  typeObject->tp_bases, index, object );
                  //   }
                  // }
                 }

                 //if( 0 != m_subClass.size() )
                 // {
                 //  if( nullptr != typeObject->tp_subclasses ) Py_DECREF( typeObject->tp_subclasses );
                 //  typeObject->tp_subclasses = PyTuple_New( m_subClass.size() );
                 //  if( nullptr != typeObject->tp_subclasses)
                 //  {
                 //    size_type index=0;
                 //    for ( auto const& item: m_subClass ) 
                 //    {
                 //     PyObject *object = const_cast<PyObject *>( item.second->handle().getO() );
                 //     PyTuple_SetItem(  typeObject->tp_subclasses, index, object );
                 //    }
                 //  }
                 // }

                 //TODO typeObject->tp_base = TODO;

                 return this->handle();
                }
             public:
               handleType_type const& handle()const
                {
                 return m_handle;
                }
             private:
               handleType_type      & handle()
                {
                 return m_handle;
                }
             private:
               mutable handleType_type m_handle;
             private:
               string_type m_doc  = "Documentation.";

             public:
               interface_type const& interface()const{ return m_interface; }
               interface_type      & interface()     { return m_interface; }
             private:
               interface_type m_interface;

             public:
               identifier_type const& identifier(  )const{ return m_identifier; }
               void identifier( identifier_type const& i ){ m_identifier = i; }
             private:
               identifier_type m_identifier;

             private:
               typedef std::map< identifier_type, typeObject_class const*> container_type;

             public: // Base classes
               void superClass( identifier_type const& id, typeObject_class const* sup )
               {
                this->m_superClass.emplace( id, sup ); 
               }
             private:
               container_type  m_superClass;

             public: // Derived classes
               void subClass(   identifier_type const& id, typeObject_class const* sub )
                {
                 this->m_subClass.emplace(id, sub ); 
                }
             private:
               container_type  m_subClass;
           };

         }
       }
     }
   }
 }

#endif
#endif
