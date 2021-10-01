#ifndef reflection_operation_transfer_tkv_scan
#define reflection_operation_transfer_tkv_scan

// ::reflection::operation::transfer::tkv::scan_struct<input_name,key_name,identifier_name,report_name,container_name>

#include "../../../type/name/id.hpp"

#include "./context.hpp"
#include "./probe.hpp"
#include "../../../content/guarded/simple.hpp"
#include "../../../utility/function/stdo.hpp"

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
           typename       input_name
          ,typename  identifier_name = std::string
          ,typename         key_name = std::string
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
          ,typename      report_name = bool
         >
         struct scan_struct
          {
           public:
             typedef      input_name          input_type;
             typedef  identifier_name    identifier_type;
             typedef         key_name           key_type;
             typedef      report_name        report_type;

           private:
             typedef std::size_t   size_type;
             typedef std::string string_type;

             typedef ::reflection::operation::transfer::tkv::context_struct<size_type> context_type;

           public:
             typedef std::shared_ptr< context_type >  context_pointer_type;
             static context_pointer_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::tkv::scan_struct<input_name,identifier_name,key_name, container_name, report_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;

             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::tkv::parser_type<input_name,identifier_name,key_name,container_name,report_name> parser_type;
             typedef typename parser_type::facility_type::property_pointer_type    property_pointer_type;
             typedef typename parser_type::facility_type::constructor_pointer_type  constructor_pointer_type;

             typedef ::reflection::operation::scan::probe::base_class< input_name, identifier_name, key_name, report_name >    probe_base_type;
             typedef ::reflection::operation::transfer::tkv::probe_class<identifier_name,key_name,report_name>                  probe_tkv_type;

             typedef ::reflection::operation::transfer::tkv::accumulator_class< input_name,identifier_name, key_name, report_name> accumulator_type;

           public:
             explicit scan_struct( parser_type &  parser_param, context_pointer_type context_param = this_type::context() )
              {
               parser_param.probe(       typename parser_type::probe_pointer_type(       new probe_tkv_type       {} ) );
               parser_param.accumulator( typename parser_type::accumulator_pointer_type( new accumulator_type {} ) );

               using namespace std::placeholders;

               this_type::template register_fundamental< bool          >(  parser_param, context_param  );

               this_type::template register_fundamental< char          >(  parser_param, context_param  );
               this_type::template register_fundamental< unsigned char >(  parser_param, context_param  );
               this_type::template register_fundamental< wchar_t       >(  parser_param, context_param  );
               this_type::template register_fundamental< std::wint_t   >(  parser_param, context_param  );
               this_type::template register_fundamental< char16_t      >(  parser_param, context_param  );
               this_type::template register_fundamental< char32_t      >(  parser_param, context_param  );

               this_type::template register_fundamental<std::uint8_t >(  parser_param, context_param  );
               this_type::template register_fundamental<std::uint16_t>(  parser_param, context_param  );
               this_type::template register_fundamental<std::uint32_t>(  parser_param, context_param  );
               this_type::template register_fundamental<std::uint64_t>(  parser_param, context_param  );

               this_type::template register_fundamental<std::int8_t >(  parser_param, context_param  );
               this_type::template register_fundamental<std::int16_t>(  parser_param, context_param  );
               this_type::template register_fundamental<std::int32_t>(  parser_param, context_param  );
               this_type::template register_fundamental<std::int64_t>(  parser_param, context_param  );

               this_type::template register_fundamental<float>(        parser_param, context_param  );
               this_type::template register_fundamental<double>(       parser_param, context_param  );
               this_type::template register_fundamental<long double>(  parser_param, context_param  );

               this_type::template register_fundamental<void*              >(  parser_param, context_param  );
               this_type::template register_fundamental<short              >(  parser_param, context_param  );
               this_type::template register_fundamental<unsigned short     >(  parser_param, context_param  );
               this_type::template register_fundamental<int                >(  parser_param, context_param  );
               this_type::template register_fundamental<unsigned           >(  parser_param, context_param  );
               this_type::template register_fundamental<long               >(  parser_param, context_param  );
               this_type::template register_fundamental<long long          >(  parser_param, context_param  );
               this_type::template register_fundamental<unsigned long      >(  parser_param, context_param  );
               this_type::template register_fundamental<unsigned long long >(  parser_param, context_param  );

               this_type::register_string< char     >(  parser_param, context_param  );
               this_type::register_string< wchar_t  >(  parser_param, context_param  );
               this_type::register_string< char16_t >(  parser_param, context_param  );
               this_type::register_string< char32_t >(  parser_param, context_param  );
              }

           private:
             template < typename data_name >
              static  property_pointer_type read_fundamental( context_pointer_type &context_param, input_type& input_param )
               {
                typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;

                size_type size;
                auto current_position = input_param.tellg();
                if( current_position == probe_tkv_type::get_size( *context_param, size, input_param ) )
                 {
                  return property_pointer_type( nullptr );
                 }

                data_name value;
                input_param.read( reinterpret_cast<char*>( &value ), sizeof( value ) );
                return property_pointer_type( new simple_type( value ) );
               }

           public:
             template < typename simple_name >
              static void register_fundamental ( parser_type &  parser_param, context_pointer_type &context_param )
               {
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_fundamental< simple_name>, context_param, std::placeholders::_1 );

                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<simple_name>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<simple_name>();
               }

           private:
             template < typename char_name >
              static property_pointer_type read_string( context_pointer_type &context_param, input_name & input_param  )
              {
               typedef std::basic_string<char_name> string_local_type;
               typedef typename ::reflection::content::guarded::simple_struct<identifier_type,string_local_type>::typedef_type simple_type;

                size_type size;
                auto current_position = input_param.tellg();
                if( current_position == probe_tkv_type::get_size( *context_param, size, input_param ) )
                 {
                  return property_pointer_type( nullptr );
                 }

               if( 0 != ( size %sizeof( char_name ) ))
                {
                 return property_pointer_type( nullptr );
                }
               string_local_type  value;
               value.resize( size / sizeof( char_name ) );
               input_param.read( const_cast<char*>( reinterpret_cast<const char*>( value.data() ) ), size * sizeof( char_name ) );
               return property_pointer_type( new simple_type( value ) );
              }
           public:
             template < typename char_name >
              static void register_string( parser_type &  parser_param,  context_pointer_type &context_param)
               {
                typedef std::basic_string<char_name> string_type;
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();
              
                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_string< char_name >, context_param, std::placeholders::_1 );

                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<string_type>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<string_type>();
               }

           public:
             template < typename class_name, typename view_name >
              static  property_pointer_type read_class( parser_type &  parser_param, context_pointer_type &context_param, input_type& input_param )
               {
                typedef typename ::reflection::content::trinity::simple_struct<identifier_type,class_name>::typedef_type simple_type;

                auto pile =  new simple_type();

                view_name view;
                view.pointer( &( pile->disclose()) );

                dynamic_cast< probe_base_type &>( *parser_param.probe() ).push();
                parser_param.parse( view, input_param );
                dynamic_cast< probe_base_type &>( *parser_param.probe() ).pop();

                return property_pointer_type( pile );
               }

           public:
             template < typename class_name, typename view_name >
              static void register_class( parser_type &  parser_param, context_pointer_type &context_param)
               {
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::template read_class<class_name, view_name>, std::ref(parser_param), context_param, std::placeholders::_1 );
                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<class_name>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<class_name>();
               }

           public:
             //template < typename POD_name >
             // static void register_container_vector_POD( parser_type &  parser_param )
             //  {
             //  typedef std::vector<POD_name> string_type;
             //   typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
             //  auto & facility = parser_param.facility();
             //
             //  std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_container_vector_POD<>, context_param, std::placeholders::_1 );
             //
             //  auto constructor = constructor_pointer_type( new overload_type( f ) );
             //
             //  facility.template insert<string_type>( constructor );
             //  }

           public:
             //template < typename simple_name >
             // static void register_container__any_POD( parser_type &  parser_param )
             //  {
             //   typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
             //   auto & facility = parser_param.facility();
             //   auto constructor = constructor_pointer_type(  new overload_class( & this_type::template read_fundamental<simple_name>) );
             //
             //   facility.template insert<simple_name>( constructor );
             //  }

          };

       }
     }
   }
 }

#endif
