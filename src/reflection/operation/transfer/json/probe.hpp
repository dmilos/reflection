#ifndef reflection_operation_transfer_json_probe
#define reflection_operation_transfer_json_probe

// ::reflection::operation::transfer::json::probe_class<identifier_name,report_name>

#include "../../scan/probe.hpp"
#include "./context.hpp"

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
           typename  identifier_name
          ,typename         key_name
          ,typename      report_name
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
             typedef  char                      char_type;
             typedef  std::string             string_type;
             typedef  std::istream             input_type;

            typedef ::reflection::operation::transfer::json::context_input_struct<string_type > context_input_type;

            typedef ::reflection::operation::transfer::json::probe_class<identifier_name,key_name,report_name > this_type;

           private:
             typedef std::streampos stream_position_type;

             struct cache_struct
              {
               bool            m_valid;
               identifier_type m_type;
               key_type        m_key;
              };

           public:
             probe_class()
              {
               this->push();
              }

           public:
             ~probe_class()
              {
              }

           public:
             report_type poke( identifier_type & indetifier_param, input_type & input_param ) override
              {
               auto & item = this->cache();
               stream_position_type stream_begin = input_param.tellg();
               key_type typeK;
               string_type typeV;
               key_type valueK;
               key_type    keyV;

               this_type::space( context(), input_param );

               if( false == quoted(    context(), input_param, keyV,   '\"'  ) ){ goto label_fail; } space( context(), input_param );
               if( false == character( context(), input_param, ':'           ) ){ goto label_fail; } space( context(), input_param );
               if( false == character( context(), input_param, '{'           ) ){ goto label_fail; } space( context(), input_param );
               if( false == quoted(    context(), input_param, typeK,  '\"'  ) ){ goto label_fail; } space( context(), input_param ); if( typeK != context().m_key.m_type ){ goto label_fail; }
               if( false == character( context(), input_param, ':'           ) ){ goto label_fail; } space( context(), input_param );
               if( false == quoted(    context(), input_param, typeV,  '\"'  ) ){ goto label_fail; } space( context(), input_param );
               if( false == character( context(), input_param, ','           ) ){ goto label_fail; } space( context(), input_param );
               if( false == quoted(    context(), input_param, valueK, '\"'  ) ){ goto label_fail; } space( context(), input_param ); if( valueK != context().m_key.m_value ){ goto label_fail; }
               if( false == character( context(), input_param, ':'           ) ){ goto label_fail; } space( context(), input_param );

               item.m_key = keyV ;
               indetifier_param = item.m_type = typeV;
               std::cout <<  " - " << __func__ <<"K: \"" << keyV << "\"; " << "type: \"" << typeV << "\""<< std::endl;
               return item.m_valid = true;

               label_fail:
                 input_param.seekg( stream_begin, std::ios_base::beg );
                 return item.m_valid  = false;
              }

            report_type skip( input_type & input_param )override
             {
              /*
                - todo
               -- find { then enclosed }
              */
              return false;
             }
           public:
            report_type eos( input_type & input_param )override
             {  std::cout<<  " - " << __func__ <<  "-"  << " begin " << std::endl;
              if( true == input_param.eof() )
               { std::cout<<  " - " << __func__ <<  "-"  << " EOF " << std::endl;
                return true;
               }
              if( false == (bool) input_param )
               { std::cout<<  " - " << __func__ <<  "-"  << " EOF " << std::endl;
                return true;
               }
              auto & item = this->cache();

              stream_position_type stream_begin = input_param.tellg();

              space( context(), input_param );
              if( false == character( context(), input_param, '}' ) )
               { std::cout<<  " - " << __func__ <<  "-"  << "no } " << std::endl;
                input_param.seekg( stream_begin, std::ios_base::beg );
                return false;
               }

              space( context(), input_param );
              if( true == character( context(), input_param, ',' ) )
               {
                return false;
               } space( context(), input_param );

              std::cout<<  " - " << __func__<< " - " << "it is EOS" << std::endl;

              return true;
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

           public:
            static bool space(     context_input_type const& contect_param ,input_type & input_param )
             {
               while( true )
                {
                 if( true == input_param.eof() )
                  {
                   break;
                  }

                 char_type  c;
                 input_param.get( c );

                 if( std::isspace( c ) ) continue;
                 input_param.unget();
                 break;
                }
              return true;
             }
            static bool character( context_input_type const& contect_param, input_type & input_param, char_type const & char_param )
             {
              stream_position_type stream_begin = input_param.tellg();
              if( true == input_param.eof() )
               {
                return false;
               }
              char_type  current;
              input_param.get( current );
              if( char_param == current )
               { std::cout <<  " - " << __func__ << " - " << " - "<< __LINE__ << " - " << " have: " << char_param << std::endl;
                return true;
               }
              std::cout <<  " - " << __func__ << " - " << " - "<< __LINE__ << " - " << " found: " << current << ";" << "expect: " << char_param <<    std::endl;
              input_param.seekg( stream_begin, std::ios_base::beg );
              return false;
             }
            static bool quoted(    context_input_type const& contect_param, input_type & input_param, string_type & value_param, char_type const& quote_param )
             {
               if( true == input_param.eof() )
               {
                return false;
               }
              stream_position_type stream_begin = input_param.tellg();

              char_type  quote;
              input_param.get( quote );
              if( quote_param != quote ){ goto label_fail; }
              value_param.clear();
              while( true )
               {
                if( true == input_param.eof() ){ goto label_fail; }
                char_type  current;
                input_param.get( current );
                if( quote_param == current )
                 {
                  break;
                 }
                value_param.push_back( current );
               }
              std::cout <<  " - " << __func__ << " - " << " - "<< __LINE__ << " - " << " have: \"" << value_param << "\"" << std::endl;
              return true;

              label_fail:
                 std::cout <<  " - " << __func__ << " - " << " - "<< __LINE__ << " - " << " Fail to get quoted string" << std::endl;
                input_param.seekg( stream_begin, std::ios_base::beg );
                return false;
             }

           public:
             cache_struct const  & cache()const{ return m_cache.back(); }
           private:
             cache_struct        & cache(){ return m_cache.back(); }
           protected:
             std::vector<cache_struct> m_cache;
           public:
             context_input_type const& context()const{ return m_context; }
             context_input_type      & context()     { return m_context; }
           private:
             context_input_type m_context;
          };

       }
     }
   }
 }

#endif
