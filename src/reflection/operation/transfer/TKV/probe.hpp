#ifndef reflection_operation_transfer_tkv_probe
#define reflection_operation_transfer_tkv_probe

// ::reflection::operation::transfer::tkv::probe_class<identifier_name,report_name>

#include "../../scan/probe.hpp"
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
           typename  identifier_name = std::string
          ,typename         key_name = std::string
          ,typename      report_name = bool
         >
         class probe_class
          : public ::reflection::operation::scan::probe::base_class< std::istream, identifier_name, key_name, report_name >
          {
           public:
             typedef  identifier_name     identifier_type;
             typedef  key_name                   key_type;
             typedef  report_name             report_type;

             typedef ::reflection::type::name::identificatorX< identifier_name > identificator_type;

             typedef  std::size_t               size_type;
             typedef  std::istream             input_type;

           private:
             typedef ::reflection::operation::transfer::tkv::context_struct<size_type> context_type;
             typedef std::streampos stream_position_type;

             struct cache_struct
              {
               bool m_valid;
               size_type   m_size=0;
               identifier_type m_type;
               key_type        m_key;
               stream_position_type   m_streamBegin;
               std::vector<std::uint8_t>   m_buffer;
              };

           public:
             probe_class()
              {
               this->push();
               m_eos.first  = "EOS";
               m_eos.second = "EOS";
              }

           public:
             ~probe_class()
              {
              }

           public:
             report_type poke( identifier_type & indetifier_param, input_type & input_param )override
              {
               this->cache().m_valid = true;
               this->cache().m_streamBegin = input_param.tellg();

               if( false == get_chunk( input_param ) )
                {
                 this->cache().m_valid = false;
                 return this->cache().m_valid;
                }
               this->cache().m_type.resize( this->cache().m_size );
               this->cache().m_type.assign( this->cache().m_buffer.begin(), this->cache().m_buffer.end() );
               indetifier_param = this->cache().m_type;

               if( false == get_chunk( input_param ) )
                {
                 this->cache().m_valid = false;
                 return this->cache().m_valid;
                }
               this->cache().m_key.resize( this->cache().m_size );
               this->cache().m_key.assign( this->cache().m_buffer.begin(), this->cache().m_buffer.end() );

               this->cache().m_size = 0;
               return this->cache().m_valid;
              }

           public:
            report_type skip( input_type & input_param )override
             {
              this->cache().m_streamBegin = input_param.tellg();
              if( false == skip( m_context, this->cache().m_size, input_param ) )
               {
                this->cache().m_valid = false;
                return false;
               }
              return true;
             }

           private:
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
            report_type eos( input_type & input_param )override
             {
              if( true == input_param.eof() )
               {
                return true;
               }
              if( false == (bool) input_param )
               {
                return true;
               }

              auto stream_begin = input_param.tellg();
              {
               for( int count =0; count < 2 ; ++count )
                {
                 if( false == get_chunk( input_param ) )
                  {
                   goto label_not_eos;
                  }
                 if( m_eos.first.size() != this->cache().m_size )
                  {
                   goto label_not_eos;
                  }
                 if(    ( this->cache().m_buffer[0] != m_eos.first[0] )
                     || ( this->cache().m_buffer[1] != m_eos.first[1] )
                     || ( this->cache().m_buffer[2] != m_eos.first[2] )
                   )
                  {
                   goto label_not_eos;
                  }
                }
               return true;
              }
              label_eos: ;

              label_not_eos:
                this->cache().m_valid = false;
                input_param.seekg( stream_begin, std::ios_base::beg );
                return false;
             }

           public:
            key_type const&   key()const override
             {
              return this->cache().m_key;
             }

           public:
             void push()override
              {
               m_cache.push_back( cache_struct{} );
              }

           public:
             void pop()override
              {
               m_cache.pop_back( );
              }

           private:
             report_type get_chunk( input_type & input_param )
              {
               this->cache().m_valid = true;
               this->cache().m_streamBegin = input_param.tellg();
               if( this->cache().m_streamBegin == get_size( m_context, this->cache().m_size, input_param ) )
                {
                 this->cache().m_valid = false;
                 return this->cache().m_valid;
                }

               this->cache().m_buffer.resize(  this->cache().m_size );
               input_param.read( const_cast<char*>( reinterpret_cast< const char*>( this->cache().m_buffer.data() ) ), this->cache().m_size );
               if( false == (bool)input_param)
                {
                 this->cache().m_valid = false;
                 return this->cache().m_valid;
                }

               return this->cache().m_valid;
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

           private:
             typedef std::pair<identifier_type, key_type> EOS_type;
             //EOS_type const& eos( )const
             // {
             //  return m_eos;
             // }
           private:
              EOS_type m_eos;

           public:
             cache_struct const  & cache()const{ return m_cache.back(); }
           private:
             cache_struct        & cache(){ return m_cache.back(); }
           protected:
             std::vector<cache_struct> m_cache;
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
