#ifndef reflection_operation_transfer_avro_print
#define reflection_operation_transfer_avro_print

// ::reflection::operation::transfer::avro_class<output_name,key_name,type_name>

#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../content/typedef/typedef.hpp"
#include "../../../content/enum/enum.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/encode/observe.hpp"





namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace avro
       {

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct print_struct
          {
           public:
             typedef      output_name        output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

           private:
             typedef std::size_t size_type;

             typedef ::reflection::operation::transfer::avro::context_struct<output_name> context_type;

           public:
             typedef std::shared_ptr< context_type >  context_pointer_type;
             static context_pointer_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::avro::print_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::encode::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit print_struct( observe_type & observe_param, context_pointer_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.recover( observe_type::recover_type_acquisition_index  , &this_type::recover      );
               observe_param.recover( observe_type::recover_action_acquisition_index, &this_type::recover      );
               observe_param.recover( observe_type::recover_action_fail_index,        &this_type::recover      );
               observe_param.recover( observe_type::recover_null_pointer_index,       &this_type::null_recover );

               observe_param.stage( observe_type::stage_introductum_index, std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_exodus_index ,     std::bind( &this_type::exodus,      context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prolog_index,      std::bind( &this_type::prolog,      context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_epilog_index ,     std::bind( &this_type::epilog,      context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prefix_index,      std::bind( &this_type::prefix,      context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_suffix_index,      std::bind( &this_type::suffix,      context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_stasimon_index ,   std::bind( &this_type::stasimon,    context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  bool          >(), std::bind( &this_type::primitive<bool          >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< char           >(), std::bind( &this_type::primitive< char          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned char  >(), std::bind( &this_type::primitive< unsigned char >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< wchar_t        >(), std::bind( &this_type::primitive< wchar_t       >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::wint_t    >(), std::bind( &this_type::primitive< std::wint_t   >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< char16_t       >(), std::bind( &this_type::primitive< char16_t      >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< char32_t       >(), std::bind( &this_type::primitive< char32_t      >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< std::int8_t    >(), std::bind( &this_type::primitive<std::int8_t   >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::int16_t   >(), std::bind( &this_type::primitive<std::int16_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::int32_t   >(), std::bind( &this_type::primitive<std::int32_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::int64_t   >(), std::bind( &this_type::primitive<std::int64_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::uint8_t   >(), std::bind( &this_type::primitive<std::uint8_t  >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::uint16_t  >(), std::bind( &this_type::primitive<std::uint16_t >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::uint32_t  >(), std::bind( &this_type::primitive<std::uint32_t >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< std::uint64_t  >(), std::bind( &this_type::primitive<std::uint64_t >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<       float    >(), std::bind( &this_type::primitive<     float    >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<      double    >(), std::bind( &this_type::primitive<    double    >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  long double   >(), std::bind( &this_type::primitive<long double   >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< short          >(), std::bind( &this_type::primitive< short         >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned short >(), std::bind( &this_type::primitive< unsigned short>, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< int            >(), std::bind( &this_type::primitive< int           >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned       >(), std::bind( &this_type::primitive< unsigned      >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< long           >(), std::bind( &this_type::primitive< long          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< long long      >(), std::bind( &this_type::primitive< long long     >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned long     >(), std::bind( &this_type::primitive< unsigned long          >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< unsigned long long>(), std::bind( &this_type::primitive< unsigned long long     >, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< void*     >(), std::bind( &this_type::primitive<void*         >, context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get< nullptr_t >(), std::bind( &this_type::null_value, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get< std::string   >(), &this_type::string  );
               observe_param.insert( identificator_type::template get< std::wstring  >(), &this_type::wstring  );


              }

           private:
             typedef    std::string       string_type;
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //output_param << "; // Continue like nothing happen." << std::endl;

               return report_type( true );
              }
             static report_type null_recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param <<  "null" << std::endl;
               return true;
              }

             static report_type introductum(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->indent(output_param);
               output_param << "{";
               context_param->newl(output_param);
               context_param->inc();
               return report_type( true );
              }
             static report_type exodus  ( context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec();
               context_param->indent(output_param);
               output_param << "}";
               context_param->newl(output_param);
               return report_type( true );
              }

             static report_type prolog(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->indent(output_param);
               output_param << "{";
               context_param->newl(output_param);
               context_param->inc();
               return report_type( true );
              }
             static report_type epilog  ( context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec();
               context_param->indent(output_param);
               output_param << "}";
               context_param->newl(output_param);
               return report_type( true );
              }

             static report_type prefix( context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;

               context_param->next();
               return report_type( result );
              }

             static report_type suffix(   context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec();
               context_param->dec();
               context_param->indent(output_param); 
               output_param <<  "}";
               context_param->newl(output_param);
               return report_type( true );
              }

             static report_type stasimon( context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->indent(output_param);
               output_param <<  ",";
               context_param->newl(output_param);
               return report_type( true );
              }

             static report_type null_value  (      context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef ::reflection::property::null_class null_type;
               auto null = dynamic_cast< null_type const* >( &property_param );
               if( nullptr == null )
                {
                 return report_type( false );
                }

               output_param << "\"" << key_param << "\"" << ": " <<  "null" << std::endl;
               return report_type( true );
              }
             static report_type string(          context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  context_param->indent(output_param); output_param << "\""<<  inspect->present() << "\""; context_param->newl(output_param);
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  context_param->indent(output_param); output_param << "\""<<  direct_instance->disclose() << "\""; context_param->newl(output_param);
                  return report_type( true );
                 }
               }
               context_param->indent(output_param); output_param << "\"" << "note" << "\"" << ": " << "\""<<  "Can not retrieve the value." << "\""; context_param->newl(output_param);
               return report_type( true );
              }

             static report_type wstring(         context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               {
                typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                auto inspect = dynamic_cast< inspect_type const* >( &property_param );
                if( nullptr != inspect )
                 {
                  // TODO output_param << "\""<<  inspect->present() << "\"";
                  return report_type( true );
                 }
               }
               {
                typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                if( nullptr != direct_instance )
                 {
                  // TODO output_param << "\""<<  direct_instance->disclose() << "\"";
                  return report_type( true );
                 }
               }

               return report_type( true );
              }
             template< typename simple_name >
              static report_type primitive(      context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                {
                 typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   context_param->indent(output_param); output_param << inspect_instance->present();  output_param << std::endl;
                   return report_type( true );
                  }
                }

                {
                 typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   context_param->indent(output_param); output_param << direct_instance->disclose(); output_param << std::endl;
                   return report_type( true );
                  }
                }

                {
                 context_param->indent(output_param);output_param<< "{ " << "\"note\" : " << "\"Can not retrieve value.\"" << "}"; output_param << std::endl;
                }

                return report_type( true );
               }


          };

       }
     }
   }
 }

#endif
