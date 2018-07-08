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
         typename output_name //!< conect operator << ()
        ,typename    key_name = std::string
        ,typename   type_name = std::string
        ,typename   report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct xml_struct
        {
         public:
           typedef  output_name     output_type;
           typedef     key_name        key_type;
           typedef    type_name       type_type;
           typedef    report_name    report_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<type_type>             category_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef typename std::add_const< property_type >::type                          property_qualified_type;
           typedef typename std::add_lvalue_reference<property_qualified_type>::type     property_qualified_reference_type;

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, type_type, report_type, std::add_const, container_name > observe_type;

           xml_struct( observe_type & observe_param )
            {     
             observe_param.recover( observe_type::not_category_index  , &xml_struct::recover );
             observe_param.recover( observe_type::missing_action_index, &xml_struct::recover );
             observe_param.recover( observe_type::action_fail_index   , &xml_struct::recover );

             observe_param.protocol().emplace( typeid(  std::string    ).name(), &xml_struct::simple<std::string   >  );
            // TODO observe_param.protocol().emplace( typeid(  std::wstring   ).name(), &xml_struct::simple<std::wstring  >  );

             observe_param.protocol().emplace( typeid(  char           ).name(), &xml_struct::simple<char          >  );
             observe_param.protocol().emplace( typeid(  unsigned char  ).name(), &xml_struct::simple<unsigned char >  );
             observe_param.protocol().emplace( typeid(  wchar_t        ).name(), &xml_struct::simple<wchar_t  >  );
             observe_param.protocol().emplace( typeid(  std::wint_t    ).name(), &xml_struct::simple<std::wint_t   >  );

             observe_param.protocol().emplace( typeid(  std::int8_t    ).name(), &xml_struct::simple<std::int8_t   >  );
             observe_param.protocol().emplace( typeid(  std::int16_t   ).name(), &xml_struct::simple<std::int16_t  >  );
             observe_param.protocol().emplace( typeid(  std::int32_t   ).name(), &xml_struct::simple<std::int32_t  >  );
             observe_param.protocol().emplace( typeid(  std::int64_t   ).name(), &xml_struct::simple<std::int64_t  >  );

             observe_param.protocol().emplace( typeid(  std::uint8_t   ).name(), &xml_struct::simple<std::uint8_t  >  );
             observe_param.protocol().emplace( typeid(  std::uint16_t  ).name(), &xml_struct::simple<std::uint16_t >  );
             observe_param.protocol().emplace( typeid(  std::uint32_t  ).name(), &xml_struct::simple<std::uint32_t >  );
             observe_param.protocol().emplace( typeid(  std::uint64_t  ).name(), &xml_struct::simple<std::uint64_t >  );

             observe_param.protocol().emplace( typeid(       float     ).name(), &xml_struct::simple<     float    >  );
             observe_param.protocol().emplace( typeid(      double     ).name(), &xml_struct::simple<    double    >  );
             observe_param.protocol().emplace( typeid(  long double    ).name(), &xml_struct::simple<long double   >  );

             observe_param.protocol().emplace( typeid(  void*          ).name(), &xml_struct::simple<void*         >  );
             observe_param.protocol().emplace( typeid(  short          ).name(), &xml_struct::simple<short         >  );
             observe_param.protocol().emplace( typeid(  unsigned short ).name(), &xml_struct::simple<unsigned short>  );
             observe_param.protocol().emplace( typeid(  int            ).name(), &xml_struct::simple<int           >  );
             observe_param.protocol().emplace( typeid(  unsigned       ).name(), &xml_struct::simple<unsigned      >  );
             observe_param.protocol().emplace( typeid(  long           ).name(), &xml_struct::simple<long          >  );
             observe_param.protocol().emplace( typeid(  long long      ).name(), &xml_struct::simple<long long     >  );

             //TODO observe_param.protocol().emplace( typeid(  nullptr_t     ).name(), &xml_struct::simple<nullptr_t     >               );
            }

           // wstring processing

           template< typename simple_name >
            static report_type simple( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

           static bool recover(       output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

           static bool structure(     output_name & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param  )
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
