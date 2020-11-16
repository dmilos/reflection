#ifndef reflection_operation_transfer_tlv_probe
#define reflection_operation_transfer_tlv_probe

// ::reflection::operation::transfer::tlv::probe_class<identifier_name,report_name>

#include "../../scan/probe.hpp"
#include "./context.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace tlv
       {

        template
         <
           typename  identifier_name = std::string
          ,typename      report_name = bool
         >
         class probe_class
          : public ::reflection::operation::scan::probe_class< std::istream, identifier_name, report_name >
          {
           public:
             typedef  identifier_name     identifier_type;
             typedef  std::istream             input_type;
             typedef  report_name             report_type;

             typedef  std::size_t             size_type;

             typedef ::reflection::type::name::identificatorX< identifier_name > identificator_type;

           public:
             typedef ::reflection::operation::transfer::tlv::context_struct<size_type> context_type;
             typedef std::streampos stream_position_type;

             struct cache_struct
              {
               bool m_valid;
               size_type   m_size;
               identifier_type m_identifier;
               identifier_type m_type;
               std::string     m_key;
               stream_position_type   m_streamBegin;
               std::vector<std::uint8_t>   m_buffer;
              };


           public:
             probe_class()
              {
              }

             ~probe_class()
              {
              }

           private:

             report_type get_chuk( input_type & input_param )
              {
               m_cache.m_valid = true;
               m_cache.m_streamBegin = input_param.tellg();
               if( m_cache.m_streamBegin == get_size( m_context, m_cache.m_size, input_param ) )
                {
                 m_cache.m_valid = false;
                 return m_cache.m_valid;
                }

               m_cache.m_buffer.resize(  m_cache.m_size );
               input_param.read( const_cast<char*>( reinterpret_cast< const char*>( m_cache.m_buffer.data() ) ), m_cache.m_size );
               if( false == (bool)input_param)
                {
                 m_cache.m_valid = false;
                 return m_cache.m_valid;
                }

               return m_cache.m_valid;
              }

           public:
             report_type poke( identifier_type & indetifier_param, input_type & input_param )
              {
               m_cache.m_valid = true;
               m_cache.m_streamBegin = input_param.tellg();

               if( false == get_chuk( input_param ) )
                {
                 m_cache.m_valid = false;
                 return m_cache.m_valid;
                }
               m_cache.m_type.resize( m_cache.m_size );
               m_cache.m_type.assign( m_cache.m_buffer.begin(), m_cache.m_buffer.end() );
               indetifier_param = m_cache.m_type;

               if( false == get_chuk( input_param ) )
                {
                 m_cache.m_valid = false;
                 return m_cache.m_valid;
                }
               m_cache.m_key.resize( m_cache.m_size );
               m_cache.m_key.assign( m_cache.m_buffer.begin(), m_cache.m_buffer.end() );

               return m_cache.m_valid;
              }

           public:
            static report_type skip( context_type const& contect_param, size_type & size, input_type & input_param )
             {
              auto current_position = input_param.tellg();
              if( current_position == get_size( contect_param, size, input_param ) )
               {
                return false;
               }
              input_param.seekg( size, std::ios_base::cur );
              return true;
             }

           public:
            report_type skip( input_type & input_param )
             {
              m_cache.m_streamBegin = input_param.tellg();
              if( false == skip( m_context, m_cache.m_size, input_param ) )
               {
                m_cache.m_valid = false;
                return false;
               }
              return true;
             }

           public:
             static stream_position_type get_size( context_type const& contect_param, size_type & size, input_type & input_param )
              {
               stream_position_type stream_begin = input_param.tellg();
               switch( contect_param.size_size )
                {
                 case( 1 ):{ std::uint8_t  s; input_param.read( reinterpret_cast<char*>( &s ), 1 ); size = static_cast<size_type>( s ); } break;
                 case( 2 ):{ std::uint16_t s; input_param.read( reinterpret_cast<char*>( &s ), 2 ); size = static_cast<size_type>( s ); } break;
                 case( 4 ):{ std::uint32_t s; input_param.read( reinterpret_cast<char*>( &s ), 4 ); size = static_cast<size_type>( s ); } break;
                 case( 8 ):{ std::uint64_t s; input_param.read( reinterpret_cast<char*>( &s ), 8 ); size = static_cast<size_type>( s ); } break;
                }
               if( false == (bool)input_param )
                {
                 input_param.seekg( stream_begin, std::ios_base::beg );
                }
               return input_param.tellg();
              }
           public:
             cache_struct const  & cache()const{ return m_cache; }
           protected:
             cache_struct m_cache;
           public:
             context_type const& context()const{ return m_context; }
             context_type      & context()     { return m_context; }
           private:
             context_type m_context;
          };

       }
     }
   }
 }

#endif
