#ifndef reflection_object_transfer_xml
#define reflection_object_transfer_xml

// ::reflection::object::transfer::xml_class<output_name,key_name,type_name>

#include "../type/category.hpp"
#include "./structure.hpp"

namespace reflection
 {
  namespace object
   {
    namespace transfer
     {

      template
       <
         typename output_name
        ,typename    key_name = std::string
        ,typename   type_name = std::string
       >
       struct xml_class
        {
         public:
           typedef  output_name     output_type;
           typedef     key_name        key_type;
           typedef    type_name       type_type;

           typedef ::type::category::pure_class<type_name>           category_type;
           typedef ::reflection::object::structure_class<key_name>  structure_type;
           typedef ::reflection::property::pure_class                property_type;

           typedef  ::reflection::object::observe_class<output_name,key_name,type_name> observe_type;

           template< typename simple_name >
            static bool simple( key_type const& key_param, property_type const& property_param, output_name & output_param )
             {
              output_param << "<item ";
              output_param << "name=\"" << key_param << "\" ";

              {
               category_type const* category = dynamic_cast< category_type const* >( &property_param );
               if( nullptr != category )
                {
                 output_param << "type=\"" << category->type() << "\" ";
                }
               else
                {
                 output_param << "note=\"Can not detect type\" ";
                }
              }

              output_param << ">";

              if( true == ::reflection::property::inspect::check< simple_name const&>( property_param ) )
               {
                output_param << ::reflection::property::inspect::present<simple_name const&>( property_param );
               }

              output_param << "</item>";
              output_param << std::endl;
              return true;
             }


           static bool recover( key_type const& key_param, property_type const& property_param, output_name & output_param )
            {
             output_param << "<item ";
             output_param << "name=\"" << key_param << "\" ";

             {
              category_type const* category = dynamic_cast< category_type const* >( &property_param );
              if( nullptr != category )
               {
                output_param << "type=\"" << category->type() << "\" ";
               }
              else
               {
                output_param << "note=\"Can not detect type\" ";
               }
             }

             output_param << "note=\"Unhandled item\" ";

             output_param << ">";
             output_param << "</item>" ;
             output_param << std::endl;

             return true;
            }

           static bool structure( observe_type const& observe_param,  key_type const& key_param, property_type const& property_param, output_name & output_param )
            {
             output_param << "<item ";
             output_param << "name=\"" << key_param    << "\" ";
             {
              category_type const* category = dynamic_cast< category_type const* >( &property_param );
              if( nullptr != category )
               {
                output_param << "type=\"" << category->type() << "\" ";
               }
              else
               {
                output_param << "note=\"Can not detect type\" ";
               }
             }
             output_param << ">";
             output_param << std::endl;

             observe_param.view( ::reflection::property::inspect::present< structure_type const& >( property_param ), output_param );

             output_param << "</item>";
             output_param << std::endl;
             return true;
            }

       };

     }
   }
 }

#endif
