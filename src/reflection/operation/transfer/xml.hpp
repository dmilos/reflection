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
        ,typename      key_name = std::string
        ,typename     type_name = std::string
        ,typename   report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct xml_struct
        {
         public:
           typedef  output_name     output_type;
           typedef     key_name        key_type;
           typedef    type_name       type_type;
           typedef    report_name   report_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<type_type>             category_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef typename std::add_const< property_type >::type                                  property_qualified_type;
           typedef typename std::add_lvalue_reference<property_qualified_type>::type     property_qualified_reference_type;

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, type_type, report_type, std::add_const, container_name > observe_type;

           xml_struct( observe_type & observe_param )
            {
             observe_param.recover( observe_type::not_category_index  , &xml_struct::recover );
             observe_param.recover( observe_type::missing_action_index, &xml_struct::recover );
             observe_param.recover( observe_type::action_fail_index   , &xml_struct::recover );

             observe_param.insert( typeid(  std::string    ).name(), &xml_struct::primitive<std::string   >  );
            // TODO observe_param.insert( typeid(  std::wstring   ).name(), &xml_struct::primitive<std::wstring  >  );

             observe_param.insert( typeid(  char           ).name(), &xml_struct::primitive<char          >  );
             observe_param.insert( typeid(  unsigned char  ).name(), &xml_struct::primitive<unsigned char >  );
             observe_param.insert( typeid(  wchar_t        ).name(), &xml_struct::primitive<wchar_t  >  );
             observe_param.insert( typeid(  std::wint_t    ).name(), &xml_struct::primitive<std::wint_t   >  );

             observe_param.insert( typeid(  std::int8_t    ).name(), &xml_struct::primitive<std::int8_t   >  );
             observe_param.insert( typeid(  std::int16_t   ).name(), &xml_struct::primitive<std::int16_t  >  );
             observe_param.insert( typeid(  std::int32_t   ).name(), &xml_struct::primitive<std::int32_t  >  );
             observe_param.insert( typeid(  std::int64_t   ).name(), &xml_struct::primitive<std::int64_t  >  );

             observe_param.insert( typeid(  std::uint8_t   ).name(), &xml_struct::primitive<std::uint8_t  >  );
             observe_param.insert( typeid(  std::uint16_t  ).name(), &xml_struct::primitive<std::uint16_t >  );
             observe_param.insert( typeid(  std::uint32_t  ).name(), &xml_struct::primitive<std::uint32_t >  );
             observe_param.insert( typeid(  std::uint64_t  ).name(), &xml_struct::primitive<std::uint64_t >  );

             observe_param.insert( typeid(       float     ).name(), &xml_struct::primitive<     float    >  );
             observe_param.insert( typeid(      double     ).name(), &xml_struct::primitive<    double    >  );
             observe_param.insert( typeid(  long double    ).name(), &xml_struct::primitive<long double   >  );

             observe_param.insert( typeid(  void*          ).name(), &xml_struct::primitive<void*         >  );
             observe_param.insert( typeid(  short          ).name(), &xml_struct::primitive<short         >  );
             observe_param.insert( typeid(  unsigned short ).name(), &xml_struct::primitive<unsigned short>  );
             observe_param.insert( typeid(  int            ).name(), &xml_struct::primitive<int           >  );
             observe_param.insert( typeid(  unsigned       ).name(), &xml_struct::primitive<unsigned      >  );
             observe_param.insert( typeid(  long           ).name(), &xml_struct::primitive<long          >  );
             observe_param.insert( typeid(  long long      ).name(), &xml_struct::primitive<long long     >  );

             observe_param.insert( typeid(  nullptr_t     ).name(), &xml_struct::null   );

             {
              using namespace std::placeholders;
              auto f = std::bind( &xml_struct::structure, _1, std::ref(observe_param), _2, _3 );
              observe_param.insert( typeid(  structure_type      ).name(), f );
             }
            }

           // wstring processing

           template< typename simple_name >
            static report_type primitive( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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
              else
               {
                if( true == ::reflection::property::direct::check< simple_name &>( const_cast< property_type &>( property_param ) ) )
                 {
                  output_param << ::reflection::property::direct::disclose<simple_name &>( const_cast< property_type &>( property_param ) );
                 }
               }

              output_param << "</item>";
              output_param << std::endl;
              return report_type( true );
             }

           static report_type recover(       output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

             return report_type( true );
            }

           static report_type structure(     output_name & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param  )
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
             return report_type( true );
            }


           static report_type null     ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             typedef ::reflection::property::null_class null_type;
             auto null = dynamic_cast< null_type const* >( &property_param );
             if( nullptr == null )
              {
               return report_type( false );
              }

             output_param <<  key_param << ": " <<  "null" << std::endl;
             output_param << "<item ";
             output_param << "name=\"" << key_param << "\" ";
             output_param << "value=\"null";
             output_param << "/>";

             return report_type( true );
            }

       };

     }
   }
 }

#endif
