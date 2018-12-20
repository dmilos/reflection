#ifndef reflection_content_function_parameter
#define reflection_content_function_parameter

// ::reflection::content::function::parameter_class<identifier_name>

#include "../../type/name/id.hpp"

namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identifier_name
      //,typename name_name
       >
       class parameter_class
        {
         public:
           typedef identifier_name identifier_type;
         //typedef std::string        string_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           parameter_class(  )
            {
             m_original = identificator_type::template get< void >();
             m_instance = identificator_type::template get< void >();
            }

           parameter_class( identifier_type const& o, identifier_type const& i )
            {
             m_original = o;
             m_instance = i;
            }
            
           parameter_class &operator=( identifier_type const& i )
            {
             m_original = i;
             m_instance = i;
             return *this;
            }

           identifier_type const& original()const{ return m_original; }
           identifier_type const& instance()const{ return m_instance; }

         public:
             identifier_type m_original;
             identifier_type m_instance;
          //string_type m_name;
        };

     }
   }
 }

#endif
