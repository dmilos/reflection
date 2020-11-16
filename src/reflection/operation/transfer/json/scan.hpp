#ifndef reflection_operation_transfer_json_scan
#define reflection_operation_transfer_json_scan

// ::reflection::operation::transfer::json::scan_struct<input_name,key_name,identifier_name,report_name,container_name>

#include "./context.hpp"

#include "../../../type/name/id.hpp"
#include "../../../content/guarded/simple.hpp"
#include "../../../utility/function/stdo.hpp"

#include "./probe.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace json
       {

        template
         <
           typename       input_name
          ,typename  identifier_name
          ,typename         key_name
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
          ,typename      report_name = bool
         >
         struct scan_struct
          {
           public:
             typedef      input_name          input_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

           private:
             typedef std::size_t   size_type;
             typedef std::string string_type;

             typedef ::reflection::operation::transfer::json::context_input_struct< string_type > context_input_type;

           public:
             typedef std::shared_ptr< context_input_type >  context_input_pointer_type;
             static context_input_pointer_type context(){ return std::make_shared<context_input_type>(); }

           public:
             typedef ::reflection::operation::transfer::json::scan_struct<input_name,identifier_name,key_name, container_name, report_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;

             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::json::parser_type<input_name,identifier_name,key_name,container_name,report_name> parser_type;
             typedef typename parser_type::facility_type::property_pointer_type    property_pointer_type;
             typedef typename parser_type::facility_type::constructor_pointer_type  constructor_pointer_type;

             typedef ::reflection::operation::scan::probe::base_class< input_name, identifier_name, key_name, report_name >    probe_base_type;
             typedef ::reflection::operation::transfer::json::probe_class<identifier_name,key_name,report_name>                probe_json_type;

             typedef ::reflection::operation::transfer::json::accumulator_class< input_name,identifier_name, key_name, report_name> accumulator_type;

           public:
             explicit scan_struct( parser_type &  parser_param, context_input_pointer_type context_param = this_type::context() )
              {
               parser_param.probe(       typename parser_type::probe_pointer_type(       new probe_json_type  {} ) );
               parser_param.accumulator( typename parser_type::accumulator_pointer_type( new accumulator_type {} ) );

               using namespace std::placeholders;

               this_type::template register_bool< bool          >(  context_param, parser_param );

               this_type::template register_integral< char          >(  context_param, parser_param );
               this_type::template register_natural< unsigned char >(  context_param, parser_param );
               this_type::template register_integral< wchar_t       >(  context_param, parser_param );
               this_type::template register_integral< std::wint_t   >(  context_param, parser_param );
               this_type::template register_integral< char16_t      >(  context_param, parser_param );
               this_type::template register_integral< char32_t      >(  context_param, parser_param );

               this_type::template register_natural<std::uint8_t >(  context_param, parser_param );
               this_type::template register_natural<std::uint16_t>(  context_param, parser_param );
               this_type::template register_natural<std::uint32_t>(  context_param, parser_param );
               this_type::template register_natural<std::uint64_t>(  context_param, parser_param );

               this_type::template register_integral<std::int8_t >(   context_param, parser_param );
               this_type::template register_integral<std::int16_t>(   context_param, parser_param );
               this_type::template register_integral<std::int32_t>(   context_param, parser_param );
               this_type::template register_integral<std::int64_t>(   context_param, parser_param );

               this_type::template register_decimal<float>(       context_param, parser_param );
               this_type::template register_decimal<double>(      context_param, parser_param );
               this_type::template register_decimal<long double>( context_param, parser_param );

               // TODO this_type::template register_integral<void*              >(  context_param, parser_param );
               this_type::template register_integral<short              >(  context_param, parser_param );
               this_type::template register_natural<unsigned short     >(  context_param, parser_param );
               this_type::template register_integral<int                >(  context_param, parser_param );
               this_type::template register_natural<unsigned           >(  context_param, parser_param );
               this_type::template register_integral<long               >(  context_param, parser_param );
               this_type::template register_integral<long long          >(  context_param, parser_param );
               this_type::template register_natural<unsigned long      >(  context_param, parser_param );
               this_type::template register_natural<unsigned long long >(  context_param, parser_param );

               this_type::register_string< char     >(   context_param, parser_param );
               //  TODO this_type::register_string< wchar_t  >(   context_param, parser_param );
               //  TODO this_type::register_string< char16_t >(   context_param, parser_param );
               //  TODO this_type::register_string< char32_t >(   context_param, parser_param );
              }

           private:
             template < typename data_name >
              static  property_pointer_type read_bool( context_input_pointer_type &context_param, input_type& input_param )
               { std::cout << __func__ << " - "<< __LINE__ << std::endl;
                typedef char char_type;
                typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;

                string_type true_string="true", false_string="true";
                auto current_position = input_param.tellg();

                // TODO take first char, check against T or F,
                // TODO parse rest of characters.
                data_name value = true;

                return property_pointer_type( new simple_type( value ) );
               }

           public:
             template < typename simple_name >
              static void register_bool( context_input_pointer_type &context_param, parser_type &  parser_param )
               {
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_bool< simple_name>, context_param, std::placeholders::_1 );

                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<simple_name>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<simple_name>();
               }

           private:
             template < typename data_name >
              static  property_pointer_type read_natural( context_input_pointer_type &context_param, input_type& input_param )
               { std::cout << __func__ << " - "<< __LINE__ << std::endl;
                typedef char char_type;
                typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;
                bool succes = false;
                auto start_position = input_param.tellg();

                data_name value = 0;
                data_name power = 1;
                while( true )
                 {
                  if( true == input_param.eof() ){ break; }
                  char_type  current;
                  input_param.get( current );
                  if( 0 != isdigit( current ) )
                   {
                    value = value * 10 + ( current - '0' );
                    succes = true;
                    continue;
                   }
                  input_param.unget();
                  break;
                 }

                if( false == succes )
                 {
                  input_param.seekg( start_position, std::ios_base::beg );
                  return property_pointer_type( nullptr );
                 }
                std::cout << __func__ << " - "<< __LINE__ << " - " << value << std::endl;
                return property_pointer_type( new simple_type( value ) );
               }

           public:
             template < typename simple_name >
              static void register_natural( context_input_pointer_type &context_param, parser_type &  parser_param )
               {
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_natural<simple_name>, context_param, std::placeholders::_1 );

                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<simple_name>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<simple_name>();
               }

           private:
             template < typename data_name >
              static  property_pointer_type read_integral( context_input_pointer_type &context_param, input_type& input_param )
               { std::cout << __func__ << " - "<< __LINE__ << std::endl;
                typedef char char_type;
                typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;
                bool succes = false;
                auto start_position = input_param.tellg();
                data_name signum = 1;

                if( true == probe_json_type::character( *context_param, input_param, '+' ) )
                 {
                  signum = +1; probe_json_type::space( *context_param, input_param );
                 }
                else
                 if( true == probe_json_type::character( *context_param, input_param, '-' ) )
                  {
                   signum = -1;  probe_json_type::space( *context_param, input_param );
                  }

                data_name value = 0;
                data_name power = 1;
                while( true )
                 {
                  if( true == input_param.eof() ){ break; }
                  char_type  current;
                  input_param.get( current );
                  if( 0 != isdigit( current ) )
                   {
                    value = value * 10 + ( current - '0' );
                    succes = true;
                    continue;
                   }
                  input_param.unget();
                  break;
                 }

                if( false == succes )
                 {
                  input_param.seekg( start_position, std::ios_base::beg );
                  return property_pointer_type( nullptr );
                 }
                std::cout << __func__ << " - "<< __LINE__ << " - " << signum * value << std::endl;
                return property_pointer_type( new simple_type( signum * value ) );
               }

           public:
             template < typename simple_name >
              static void register_integral( context_input_pointer_type &context_param, parser_type &  parser_param )
               {
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_integral< simple_name>, context_param, std::placeholders::_1 );

                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<simple_name>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<simple_name>();
               }

           private:
             template < typename data_name >
              static  property_pointer_type read_decimal( context_input_pointer_type &context_param, input_type& input_param )
               {  std::cout << __func__ << " - "<< __LINE__ << std::endl;
                typedef char char_type;
                typedef typename ::reflection::content::guarded::simple_struct<identifier_type,data_name>::typedef_type simple_type;
                bool succes = false;
                auto start_position = input_param.tellg();
                data_name signum = 1;

                if( true == probe_json_type::character( *context_param, input_param, '+' ) )
                 {
                  signum = +1; probe_json_type::space( *context_param, input_param );
                 }
                else
                 if( true == probe_json_type::character( *context_param, input_param, '-' ) )
                  {
                   signum = -1;  probe_json_type::space( *context_param, input_param );
                  }

                data_name value = 0;
                data_name power = 1;
                data_name direction = 10;
                while( true )
                 {
                  if( true == input_param.eof() ){ break; }
                  char_type current;
                  input_param.get( current );
                  if( 0 != isdigit( current ) )
                   {
                    value +=  ( current - '0' ) * power;
                    power *= direction;
                    succes = true;
                    continue;
                   }
                  if( '.' == current )
                   {
                    direction = 0.1;
                    power = 0.1;
                    continue;
                   }
                  input_param.unget();
                  break;
                 }

                if( false == succes )
                 {
                  input_param.seekg( start_position, std::ios_base::beg );
                  std::cout << __func__ << " - "<< __LINE__ << " - "<< "found nothing" << std::endl;
                  return property_pointer_type( nullptr );
                 }
                std::cout << __func__ << " - "<< __LINE__<< " - " << "value: " << signum * value << std::endl;
                return property_pointer_type( new simple_type( signum * value ) );
               }

           public:
             template < typename simple_name >
              static void register_decimal( context_input_pointer_type &context_param, parser_type &  parser_param )
               {
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::read_decimal< simple_name>, context_param, std::placeholders::_1 );

                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<simple_name>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<simple_name>();
               }

           private:
             template < typename char_name >
              static property_pointer_type read_string( context_input_pointer_type &context_param, input_name & input_param  )
              {  std::cout << __func__ << " - "<< __LINE__ << std::endl;
               typedef std::basic_string<char_name> string_local_type;

               auto current_position = input_param.tellg();
               string_local_type value;
               if( false == probe_json_type::quoted( *context_param, input_param, value, '"' ) )
                {
                 return property_pointer_type( nullptr );
                }

               std::cout << __func__ << " - "<< __LINE__ << " - \"" << value << "\"" << std::endl;
               typedef typename ::reflection::content::guarded::simple_struct<identifier_type,string_local_type>::typedef_type simple_type;
               return property_pointer_type( new simple_type( value ) );
              }
           public:
             template < typename char_name >
              static void register_string( context_input_pointer_type &context_param, parser_type &  parser_param )
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

           private:
             template < typename class_name, typename view_name >
              static  property_pointer_type read_class( parser_type &  parser_param, context_input_pointer_type &context_param, input_type& input_param )
               {
                typedef typename ::reflection::content::trinity::simple_struct<identifier_type,class_name>::typedef_type simple_type;

                auto pile =  new simple_type();

                view_name view;
                view.pointer( &( pile->disclose()) );

                std::cout << __func__ << " - "<< __LINE__ << " - " << "begin" << std::endl;

                auto start_position = input_param.tellg();

                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, '{' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 } probe_json_type::space( *context_param, input_param );

                dynamic_cast< probe_base_type &>( *parser_param.probe() ).push();
                parser_param.parse( view, input_param );
                dynamic_cast< probe_base_type &>( *parser_param.probe() ).pop();

                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, '}' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 } probe_json_type::space( *context_param, input_param );

                std::cout << __func__ << " - "<< __LINE__ << " - " << "end" << std::endl;
                return property_pointer_type( pile );
               }

           public:
             template < typename class_name, typename view_name >
              static void register_class( context_input_pointer_type &context_param, parser_type &  parser_param )
               {
                typedef ::reflection::utility::function::std_overload_class<property_pointer_type,input_name&> overload_type;
                auto & facility = parser_param.facility();

                std::function< property_pointer_type ( input_name& ) > f = std::bind( &this_type::template read_class<class_name, view_name>, std::ref(parser_param), context_param, std::placeholders::_1 );
                auto constructor = constructor_pointer_type( new overload_type( f ) );

                facility.template insert<class_name>( constructor );

                auto & accumulator = dynamic_cast< accumulator_type & >( *parser_param.accumulator() );
                accumulator.equalizer().template register_default<class_name>();
               }

           private:
             template < typename class_name, typename view_name >
              static  property_pointer_type read_vector( parser_type &  parser_param, context_input_pointer_type &context_param, input_type& input_param )
              {  std::cout << __func__ << " - "<< __LINE__ << std::endl;
/*
                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, '[' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 } probe_json_type::space( *context_param, input_param );

                while( true )
                 {
                  probe_json_type::space( *context_param, input_param );
                  if( false == probe_json_type::character( *context_param, input_param, '{' ) )
                   { // TODO input_param.seekg( current_position )
                    return property_pointer_type( nullptr );
                   } probe_json_type::space( *context_param, input_param );

                  parser_param.probe()->push();
                  parser_param.parse( view, input_param );
                  parser_param.probe()->pop();

                  probe_json_type::space( *context_param, input_param );
                  if( false == probe_json_type::character( *context_param, input_param, '}' ) )
                   { // TODO input_param.seekg( current_position )
                    return property_pointer_type( nullptr );
                   } probe_json_type::space( *context_param, input_param );

                  // TODO push_back

                  if( false == probe_json_type::character( *context_param, input_param, ',' ) )
                   {
                     continue;
                   } probe_json_type::space( *context_param, input_param );
                 }

                probe_json_type::space( *context_param, input_param );
                if( false == probe_json_type::character( *context_param, input_param, ']' ) )
                 { // TODO input_param.seekg( current_position )
                  return property_pointer_type( nullptr );
                 } probe_json_type::space( *context_param, input_param );
*/
               return property_pointer_type( nullptr );
              }

          };

       }
     }
   }
 }

#endif
