#ifndef  reflection_operation_transfer_tkv_serialize
#define reflection_operation_transfer_tkv_serialize

// ::reflection::operation::transfer::tkv::serialize_struct<output_name,key_name,identifier_name,report_name,container_name>

#include "../../../type/name/id.hpp"

#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/encode/observe.hpp"

#include "./context.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace tkv
       {

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct serialize_struct
          {
           public:
             typedef      output_name        output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

           private:
             typedef std::size_t   size_type;
             typedef std::string string_type;

             typedef ::reflection::operation::transfer::tkv::context_struct<size_type> context_type;

           public:
             typedef std::shared_ptr< context_type >  context_pointer_type;
             static context_pointer_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::tkv::serialize_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

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
             explicit serialize_struct( observe_type & observe_param, context_pointer_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::structure, std::ref(observe_param), context_param, _1,_2, _3 );
                auto i = identificator_type::template get<  structure_type      >();
                observe_param.insert( i, f );
                observe_param.recover( observe_type::recover_action_acquisition_index   , f );
               }

               observe_param.stage( observe_type::stage_introductum_index, std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prolog_index,  std::bind( &this_type::prolog, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_epilog_index,  std::bind( &this_type::epilog, context_param, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prefix_index,  std::bind( &this_type::prefix, context_param, _1, _2, _3 ) );

               this_type::template register_fundamental< bool           >( observe_param, context_param  );

               this_type::template register_fundamental< char           >( observe_param, context_param  );
               this_type::template register_fundamental< unsigned char  >( observe_param, context_param  );
               this_type::template register_fundamental< wchar_t        >( observe_param, context_param  );
               this_type::template register_fundamental< std::wint_t    >( observe_param, context_param  );
               this_type::template register_fundamental< char16_t       >( observe_param, context_param  );
               this_type::template register_fundamental< char32_t       >( observe_param, context_param  );

               this_type::template register_fundamental< std::int8_t    >( observe_param, context_param  );
               this_type::template register_fundamental< std::int16_t   >( observe_param, context_param  );
               this_type::template register_fundamental< std::int32_t   >( observe_param, context_param  );
               this_type::template register_fundamental< std::int64_t   >( observe_param, context_param  );
               this_type::template register_fundamental< std::uint8_t   >( observe_param, context_param  );
               this_type::template register_fundamental< std::uint16_t  >( observe_param, context_param  );
               this_type::template register_fundamental< std::uint32_t  >( observe_param, context_param  );
               this_type::template register_fundamental< std::uint64_t  >( observe_param, context_param  );

               this_type::template register_fundamental<      float     >( observe_param, context_param  );
               this_type::template register_fundamental<     double     >( observe_param, context_param  );
               this_type::template register_fundamental< long double    >( observe_param, context_param  );

               this_type::template register_fundamental< void*             >( observe_param, context_param  );
               this_type::template register_fundamental< nullptr_t         >( observe_param, context_param  );

               this_type::template register_fundamental< short             >( observe_param, context_param  );
               this_type::template register_fundamental< unsigned short    >( observe_param, context_param  );
               this_type::template register_fundamental< int               >( observe_param, context_param  );
               this_type::template register_fundamental< unsigned          >( observe_param, context_param  );
               this_type::template register_fundamental< long              >( observe_param, context_param  );
               this_type::template register_fundamental< long long         >( observe_param, context_param  );
               this_type::template register_fundamental< unsigned long     >( observe_param, context_param  );
               this_type::template register_fundamental< unsigned long long>( observe_param, context_param  );

               this_type::template register__any< std::string    >( &this_type::string< char     >, observe_param, context_param );
               this_type::template register__any< std::wstring   >( &this_type::string< wchar_t  >, observe_param, context_param );
               this_type::template register__any< std::u16string >( &this_type::string< char16_t >, observe_param, context_param );
               this_type::template register__any< std::u32string >( &this_type::string< char32_t >, observe_param, context_param );
              }

           private:
             static report_type introductum(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }

             static report_type prolog(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }

             static report_type epilog(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_chunk( 3, "EOS", context_param, output_param );
               output_chunk( 3, "EOS", context_param, output_param );

               return report_type( true );
              }

             static report_type prefix(   context_pointer_type &context_param,  output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               category_type const* category = dynamic_cast< category_type const* >( &property_param );
               if( nullptr == category )
                {
                 return report_type( false );
                }

               auto const& id = category->identifier();
               output_chunk(        id.size(),        id.data(), context_param, output_param );

               output_chunk( key_param.size(), key_param.data(), context_param, output_param );
               return report_type( true );
              }

           private:
             typedef    bool             boolean_type;
           private:
            static bool output_size( size_type const& size_param,  context_pointer_type const &context_param, output_type & output_param  )
              {
               switch( context_param->size_size )
                {
                 case( 1 ):{ std::uint8_t  s = size_param; output_param.write( reinterpret_cast<char*>( & s), 1 ); } break; // TODO check return of write
                 case( 2 ):{ std::uint16_t s = size_param; output_param.write( reinterpret_cast<char*>( & s), 2 ); } break; // TODO check return of write
                 case( 4 ):{ std::uint32_t s = size_param; output_param.write( reinterpret_cast<char*>( & s), 4 ); } break; // TODO check return of write
                 case( 8 ):{ std::uint64_t s = size_param; output_param.write( reinterpret_cast<char*>( & s), 8 ); } break; // TODO check return of write
                 default: return false;
                }
               return true;
              }

            static bool output_chunk( size_type const& size_param,  const void * data_param,  context_pointer_type const &context_param,output_type & output_param  )
              {
               output_size( size_param, context_param, output_param );
               output_param.write( reinterpret_cast< const char * >( data_param ), size_param );
               return true;
              }

           private:
             template< typename simple_name >
              static report_type fundamental(                                         context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
               {
                simple_name const * pointer = nullptr;

                if( nullptr == pointer )
                 {
                  typedef ::reflection::property::inspect::pure_class<simple_name const& > inspect_type;
                  auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                  if( nullptr != inspect_instance )
                   {
                    pointer = & inspect_instance->present();
                   }
                 }

                if( nullptr == pointer )
                 {
                  typedef  ::reflection::property::direct::pure_class<simple_name &>         direct_type;
                  direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                  if( nullptr != direct_instance )
                   {
                    pointer = & direct_instance->disclose();
                   }
                 }

                if( nullptr == pointer )
                 {
                  return report_type( true );
                 }

                output_chunk( sizeof( simple_name ), pointer, context_param, output_param );

                return report_type( false );
               }

           private:
            template< typename char_name >
             static report_type string (                                            context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedef std::basic_string<char_name> string_type;
               string_type const * pointer = nullptr;


               if( nullptr == pointer )
                {
                 typedef ::reflection::property::inspect::pure_class<string_type const& > inspect_type;
                 auto inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   pointer = & inspect_instance->present();
                  }
                }

               if( nullptr == pointer )
                {
                 typedef  ::reflection::property::direct::pure_class<string_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   pointer = & direct_instance->disclose();
                  }
                }

               if( nullptr == pointer )
                {
                  return report_type( false );
                }

               {
                output_chunk( pointer->size() * sizeof( char_name ), pointer->data(), context_param, output_param );
               }
               return report_type( true );
              }

           private:
             static report_type structure (      observe_type const& observe_param, context_pointer_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               boolean_type pass = true;

               if( true == pass )
                {
                 typedef  ::reflection::property::inspect::pure_class<structure_type const&>         inspect_type;
                 inspect_type const*inspect_instance = dynamic_cast< inspect_type const* >( &property_param );
                 if( nullptr != inspect_instance )
                  {
                   observe_param.view( output_param, inspect_instance->present() );
                   pass = false;
                  }
                 }

               if( true == pass )
                {
                 typedef  ::reflection::property::direct::pure_class<structure_type &>         direct_type;
                 direct_type *direct_instance = dynamic_cast< direct_type * >( &const_cast< property_type &>( property_param ) );
                 if( nullptr != direct_instance )
                  {
                   observe_param.view( output_param, direct_instance->disclose() );
                   pass = false;
                  }
                }

               if( true == pass )
                {
                 // TODO
                }

               return report_type( true );
             }


           public:
             template< typename data_name, typename function_name  >
              static void register__any( function_name const& func_param, observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                auto funcBind = std::bind( func_param, context_param, _1, _2, _3 );
                return observe_param.template register__any< data_name > ( funcBind );
               }
           public:
             template< typename fundamental_name >
              static void register_fundamental( observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                auto f = std::bind( &this_type::fundamental<fundamental_name         >, context_param, _1, _2, _3 );
                return observe_param.template register__any< fundamental_name > ( f );
               }

           public:
             template< typename data_name, typename view_name>
              static void register_class( observe_type & observe_param, context_pointer_type &context_param )
               {
                using namespace std::placeholders;
                auto f = std::bind( &observe_type::template view_custom< data_name, view_name >, std::ref( observe_param ) , _1, _2, _3 );
                observe_param.template register__any< data_name >( f );
               }
          };

       }
     }
   }
 }

#endif
