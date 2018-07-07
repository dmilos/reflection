#ifndef reflection_object_transfer_xml
#define reflection_object_transfer_xml

// ::reflection::operation::transfer::xml_class<output_name,key_name,type_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"
#include "../../operation/transfer/observe.hpp"





namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename output_name
        ,typename    key_name = std::string
        ,typename   type_name = std::string
        ,typename   report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct xml_class
        {
         public:
           typedef  output_name     output_type;
           typedef     key_name        key_type;
           typedef    type_name       type_type;
           typedef    report_name    report_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<type_type>             category_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef  ::reflection::operation::transfer::observe_class<output_type,key_type,type_type> observe_type;

           template< typename simple_name >
            static report_type simple( output_type & output_param, key_type const& key_param, property_type const& property_param )
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

           static bool recover(       output_type & output_param, key_type const& key_param, property_type const& property_param )
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

           static bool structure(     output_name & output_param, observe_type const& observe_param, key_type const& key_param, property_type const& property_param  )
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

             observe_param.view( output_param, ::reflection::property::inspect::present< structure_type const& >( property_param )  );

             output_param << "</item>";
             output_param << std::endl;
             return true;
            }

       };

     }
   }
 }

#endif
