#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_methodDef
#define reflection_operation_transfer_python_bind_methodDef

// ::reflection::operation::transfer::python::bind::methodDef_class

#include <string>

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
          class methodDef_class
           {
            public:
              typedef std::string string_type;
              typedef std::size_t size_type;

            public:
              explicit methodDef_class( string_type const& name, PyCFunction const& function, int flags, string_type const& doc )
               {
                m_name     = name;
                m_function = function;
                m_flags    = flags;
                m_doc     = doc;
               }

            public:
            string_type m_name;
            PyCFunction m_function;
            int         m_flags;
            string_type m_doc;

            public:
              typedef std::vector< PyMethodDef >     containerA_type;
              typedef std::vector< methodDef_class > containerX_type;
              static void syncronize( containerA_type & A, containerX_type const& X )
               {
                A.resize( X.size() );
                for( size_type i=0; i < X.size(); ++i)
                 {
                  A[i].ml_name  = X[i].m_name.data();
                  A[i].ml_meth  = X[i].m_function;
                  A[i].ml_flags = X[i].m_flags;
                  A[i].ml_doc   = X[i].m_doc.data();
                 }
                A.push_back( PyMethodDef{ NULL, NULL, 0, NULL } );
               };

           };

         }
       }
     }
   }
 }

#endif
#endif
