#ifndef reflection_object_assign
#define reflection_object_assign

// ::reflection::object::assign<key_name>

#include "./structure.hpp"

#include "../property/assign.hpp"

namespace reflection
 {
  namespace object
   {

    template
     <
       typename  type_name = std::string
      ,typename  key_name  = std::string
     >
     class assign_class
      {
       public:
         typedef     key_name        key_type;
         typedef    type_name        type_type;

         typedef ::type::category::pure_class<type_name>           category_type;
         typedef ::reflection::property::pure_class                property_type;

         typedef std::function< void ( property_type & left_param, property_type const&right_param ) > action_type;

         typedef std::pair<type_name,type_name> pair_type;
         typedef std::map< pair_type, action_type > protocol_type;

         typedef std::array< action_type, 3 > recover_type;
         enum recover_enum { not_category_index = 0, mismatch_action_index = 1, action_fail_index = 2 };

       public:
         protocol_type    const& protocol()const{ return m_protocol; }
         protocol_type         & protocol()     { return m_protocol; }
       private:
         protocol_type m_protocol;
       public:

       public:
         void operator()
         (
           ::reflection::object::structure_class<key_name>      &  left_param
           ,::reflection::object::structure_class<key_name> const& right_param
         )
         {
          for( auto const& right_item : right_param.container() )
           {
            category_type const*  category_right = dynamic_cast< category_type const* >( right_item.second.get() );
            if( nullptr == category_right )
             {
              continue;
             }

            auto left_item = left_param.container().find( right_item.first );
            if( left_item == left_param.container().end() )
             {
              continue;
             }

            category_type const*  category_left = dynamic_cast< category_type const* >( left_item->second.get() );
            if( nullptr == category_left )
             {
              continue;
             }

            auto action = m_protocol.find( std::make_pair( category_left->type(), category_right->type() ) );
            if( m_protocol.end() == action)
             {
              continue;
             }
            action->second( *(left_item->second.get()), *(right_item.second.get()) );
           }
          return ;
         }

      };

   }
 }

#endif
