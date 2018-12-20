#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_constDef
#define reflection_operation_transfer_python_bind_constDef

// ::reflection::operation::transfer::python::bind::constDef_class

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
          class constDef_class
           {
            public:
              typedef std::string string_type;
              typedef int int_type;

            public:
              explicit constDef_class( string_type const& name, int_type const& value )
               {
                m_name     = name;
                m_value    = value;
               }

            public:
              string_type m_name;
              int_type m_value;

            public:
              typedef std::vector< constDef_class > containerX_type, containerA_type;
           };

         }
       }
     }
   }
 }

#endif
#endif
