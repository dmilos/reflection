#ifdef Py_PYTHON_H

#include "structmember.h"

#ifndef reflection_operation_transfer_python_bind_memberDef
#define reflection_operation_transfer_python_bind_memberDef

// ::reflection::operation::transfer::python::bind::memberDef_class



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
          class memberDef_class
           {
            public:
              typedef std::string string_type;
              typedef std::size_t size_type;

            public:
              explicit memberDef_class( string_type const& name, int const& type, Py_ssize_t const& offset, int flags, string_type const& doc )
               {
                m_name   = name;
                m_type   = type;
                m_offset = offset;
                m_flags  = flags;
                m_doc    = doc;
               }

            public:
            string_type m_name;
            int         m_type;
            Py_ssize_t  m_offset;
            int         m_flags;
            string_type m_doc;

            public:
              typedef std::vector< PyMemberDef >     containerA_type;
              typedef std::vector< memberDef_class > containerX_type;
              static void syncronize( containerA_type & A, containerX_type const& X )
               {
                A.resize( X.size() );
                for( size_type i=0; i < X.size(); ++i)
                 {
                  A[i].name  = const_cast<char *>( X[i].m_name.data() );
                  A[i].type  = X[i].m_type;
                  A[i].offset= X[i].m_offset;
                  A[i].flags = X[i].m_flags;
                  A[i].doc   = const_cast<char *>( X[i].m_doc.data() );
                 }
                A.push_back( PyMemberDef{ NULL, T_SHORT, 0, 0, NULL } );
               };

           };

         }
       }
     }
   }
 }

#endif
#endif
