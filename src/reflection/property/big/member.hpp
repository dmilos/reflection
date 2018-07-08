#ifndef reflection_property_big_member
#define reflection_property_big_member

// ::reflection::property::big::member_class

#include "./_pure.hpp"
#include "../direct/member.hpp"

namespace reflection
 {
  namespace property
   {
    namespace big
     {

      template
       <
        typename class_name
       >
      class member_class
       : virtual public ::reflection::property::big::pure_class< std::size_t, std::vector< std::uint8_t > >
       ,                ::reflection::property::direct::member_struct<std::vector< std::uint8_t > & ,class_name,::reflection::property::big::member_class<class_name> >
       {
        public:
          typedef class_name class_type;

          typedef class_name* pointer_type;

          typedef std::size_t size_type;
          typedef std::vector< std::uint8_t > data_type;
          typedef data_type &  (class_name::*traitor_type)();

                   member_class(){}
          explicit member_class( traitor_type const& traitor ):m_traitor(traitor){}
          virtual ~member_class(){}

          virtual size_type  size( )const
           {
            ((*m_pointer).* m_traitor)( ).size();
            return 0;
           }
          virtual size_type  size( size_type const& size_param )
           {
            ((*m_pointer).* m_traitor)().resize( size_param );
            return size();
           }
          virtual size_type  get(     data_type      & value_param,  size_type const& position_param )const
           {
            auto const& data = ((*m_pointer).* m_traitor)();
            // TODO range check
            std::copy( data.begin() + position_param, data.begin() + position_param + value_param.size(), value_param.begin() );
            return size();
           }

          virtual size_type  insert(  data_type const& value_param,  size_type const& position_param )
           {
            auto & data = ((*m_pointer).* m_traitor)();
            /*TODO*/
            return size();
           }
          virtual size_type  replace( data_type const& value_param,  size_type const& position_param )
           {
            auto & data = ((*m_pointer).* m_traitor)();
            /*TODO*/
            return size();
           }
          virtual size_type  erase(   size_type const& begin_param,   size_type const& end_param )
           {
            auto & data = ((*m_pointer).* m_traitor)();
            /*TODO*/
            return size();
           }

        public:
                  pointer_type    const& pointer()const{ return m_pointer; }
          virtual bool                   pointer( pointer_type const& pointer_param ){ m_pointer = pointer_param; return bool( true ); }
        protected:
          pointer_type        & pointer(){ return m_pointer; }
        private:
          pointer_type m_pointer;

        public:
                  traitor_type    const& traitor()const{ return m_traitor; }
          virtual bool                   traitor( traitor_type const& traitor_param ){ m_traitor = traitor_param; return bool( true ); }
        protected:
          traitor_type        & traitor(){ return m_traitor; }
        private:
          traitor_type m_traitor;
       };

        /*           TODO
      template
       <
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::big::member_class<class_name>::typedef_type
       member
        (
         original_name (class_name::*traitor_param )( void )
        )
        {
         typedef ::reflection::property::big::member_class<class_name> member_type;
         return member_type::make( traitor_param );
        }            */

     }
   }
 }

 #endif