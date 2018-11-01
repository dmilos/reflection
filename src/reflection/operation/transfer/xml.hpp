#ifndef reflection_object_transfer_xml
#define reflection_object_transfer_xml

// ::reflection::operation::transfer::xml_class<output_name,key_name,type_name>

#include "../../content/category.hpp"
#include "../../content/function/context.hpp"
#include "../../content/enum/enum.hpp"
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
         typename      output_name //!< conect operator << ()
        ,typename         key_name = std::string
        ,typename  identifier_name = std::string
        ,typename      report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct xml_struct
        {
         public:
           typedef      output_name        output_type;
           typedef         key_name           key_type;
           typedef  identifier_name    identifier_type;
           typedef      report_name        report_type;

           typedef std::size_t size_type;

           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::content::category::pure_class<identifier_type>             category_type;

           typedef typename std::add_const< property_type >::type                          property_qualified_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

         public:
           typedef ::reflection::property::structure_class<key_type,container_name>                       structure_type;
           typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>   enumeration_context_type;
           typedef ::reflection::content::function::context_class<identifier_type>                 function_context_type;

         public:
           xml_struct( observe_type & observe_param )
            {
             observe_param.control( observe_type::recover_not_category_index  , &xml_struct::recover );
             observe_param.control( observe_type::recover_missing_action_index, &xml_struct::recover );
             observe_param.control( observe_type::recover_action_fail_index   , &xml_struct::recover );

             observe_param.insert( identificator_type::template get< std::string    >(), &xml_struct::primitive<std::string   >  );
     // TODO observe_param.insert( identificator_type::template get<  std::wstring  >(), &xml_struct::primitive<std::wstring  >  );

             observe_param.insert( identificator_type::template get<  char           >(), &xml_struct::primitive<char          >  );
             observe_param.insert( identificator_type::template get<  unsigned char  >(), &xml_struct::primitive<unsigned char >  );
             observe_param.insert( identificator_type::template get<  wchar_t        >(), &xml_struct::primitive<wchar_t  >  );
             observe_param.insert( identificator_type::template get<  std::wint_t    >(), &xml_struct::primitive<std::wint_t   >  );

             observe_param.insert( identificator_type::template get<  std::int8_t    >(), &xml_struct::primitive<std::int8_t   >  );
             observe_param.insert( identificator_type::template get<  std::int16_t   >(), &xml_struct::primitive<std::int16_t  >  );
             observe_param.insert( identificator_type::template get<  std::int32_t   >(), &xml_struct::primitive<std::int32_t  >  );
             observe_param.insert( identificator_type::template get<  std::int64_t   >(), &xml_struct::primitive<std::int64_t  >  );

             observe_param.insert( identificator_type::template get<  std::uint8_t   >(), &xml_struct::primitive<std::uint8_t  >  );
             observe_param.insert( identificator_type::template get<  std::uint16_t  >(), &xml_struct::primitive<std::uint16_t >  );
             observe_param.insert( identificator_type::template get<  std::uint32_t  >(), &xml_struct::primitive<std::uint32_t >  );
             observe_param.insert( identificator_type::template get<  std::uint64_t  >(), &xml_struct::primitive<std::uint64_t >  );

             observe_param.insert( identificator_type::template get<       float     >(), &xml_struct::primitive<     float    >  );
             observe_param.insert( identificator_type::template get<      double     >(), &xml_struct::primitive<    double    >  );
             observe_param.insert( identificator_type::template get<  long double    >(), &xml_struct::primitive<long double   >  );

             observe_param.insert( identificator_type::template get<  void*          >(), &xml_struct::primitive<void*         >  );
             observe_param.insert( identificator_type::template get<  short          >(), &xml_struct::primitive<short         >  );
             observe_param.insert( identificator_type::template get<  unsigned short >(), &xml_struct::primitive<unsigned short>  );
             observe_param.insert( identificator_type::template get<  int            >(), &xml_struct::primitive<int           >  );
             observe_param.insert( identificator_type::template get<  unsigned       >(), &xml_struct::primitive<unsigned      >  );
             observe_param.insert( identificator_type::template get<  long           >(), &xml_struct::primitive<long          >  );
             observe_param.insert( identificator_type::template get<  long long      >(), &xml_struct::primitive<long long     >  );

             observe_param.insert( identificator_type::template get<  nullptr_t     >(), &xml_struct::null   );

             {
              using namespace std::placeholders;
              auto f = std::bind( &xml_struct::enumeration, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  enumeration_context_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &xml_struct::function, _1, _2, _3 );
              observe_param.insert( identificator_type::template get<  function_context_type      >(), f );
             }

             {
              using namespace std::placeholders;
              auto f = std::bind( &xml_struct::structure, _1, std::ref(observe_param), _2, _3 );
              observe_param.insert( identificator_type::template get<  structure_type      >(), f );
             }

            }

         private:
           typedef    std::string       string_type;
           typedef    std::wstring     wstring_type;
           typedef    bool             boolean_type;

           static  report_type   recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
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

           static report_type enumeration( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << "<item ";
             output_param << "name=\"" << key_param    << "\" ";

             category_type const* category = dynamic_cast< category_type const* >( &property_param );
             if( nullptr != category )
              {
               output_param << "type=\"" << "$enum" /* category->type()*/ << "\" ";
              }
             else
              {
               output_param << "note=\"Can not detect type\" ";
              }

             enumeration_context_type  const* context = dynamic_cast< enumeration_context_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << "note=\"Wrong type supplied.\" ";
               output_param << ">";
               output_param << std::endl;
               return report_type( false );
              }

             output_param << ">" << std::endl;
             for( std::size_t index=0; index < context->container().size(); ++index )
              {
               output_param << "  <parameter ";
               output_param << "ordinal=\"" << index << " ";
               output_param << "value=\""   << context->container()[index].value() << "\" ";
               output_param << "name=\""    << context->container()[index].name()  << "\" ";
               output_param << "/>";
               output_param << std::endl;
              }

             output_param << "</item>";
             output_param << std::endl;

             return report_type( true );
            }

           static report_type function ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
            {
             output_param << "<item ";
             output_param << "name=\"" << key_param    << "\" ";

             category_type const* category = dynamic_cast< category_type const* >( &property_param );

             if( nullptr != category )
              {
               output_param << "type=\"" << "$function" /* category->type()*/ << "\" ";
              }
             else
              {
               output_param << "note=\"Can not detect type\" ";
              }

             function_context_type  const* context = dynamic_cast< function_context_type const* >( &property_param );
             if( nullptr == context )
              {
               output_param << "note=\"Wrong type supplied.\" ";
               output_param << ">";
               output_param << std::endl;
               return report_type( false );
              }

             output_param << ">" << std::endl;
             for( std::size_t index=0; index < context->signature().size(); ++index )
              {
               if( context->signature()[index] == identificator_type::NAT() ) 
                {
                 continue;
                }

               output_param << "  <parameter ";
               output_param << "ordinal=\"" << index << "\" ";
               output_param << "type=\"" << context->signature()[index] << "\" ";
               output_param << "/>";
               output_param << std::endl;
              }

             output_param << "</item>";
             output_param << std::endl;

             return report_type( true );
            }

           static  report_type structure( output_name & output_param, observe_type const& observe_param, key_type const& key_param, property_qualified_reference_type property_param  )
            {
             output_param << "<item ";
             output_param << "name=\"" << key_param    << "\" ";
             {
              category_type const* category = dynamic_cast< category_type const* >( &property_param );
              if( nullptr != category )
               {
                output_param << "type=\"" << "$structure"/*category->type()*/ << "\" ";
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

       };

     }
   }
 }

#endif
