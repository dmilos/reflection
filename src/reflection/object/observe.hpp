#ifndef reflection_object_observe
#define reflection_object_observe

// ::reflection::object::observe_class<output_name,key_name,type_name>

#include "../type/category.hpp"
#include "./structure.hpp"

namespace reflection
 {
  namespace object
   {

    template
     <
       typename output_name
      ,typename    key_name = std::string
      ,typename   type_name = std::string
    //,template   modofier_name< typename class_name >
     >
     class observe_class
      {
       public:
         typedef  output_name     output_type;
         typedef     key_name        key_type;
         typedef    type_name       type_type;

         typedef ::type::category::pure_class<type_name>           category_type;
         typedef ::reflection::object::structure_class<key_name>  structure_type;
         typedef ::reflection::property::pure_class                property_type;

         typedef std::function< bool ( key_name const&, property_type const&, output_type & ) > action_type;
         typedef std::map< type_name, action_type > protocol_type;

        public:
         observe_class()
          :m_recover( []( key_name const&, property_type const&, output_type & ){return true; })
          {
          }

        public:
          action_type    const&recover()const{ return m_recover; }
          bool                  recover( action_type const& recover_param ){ m_recover = recover_param; return bool( true ); }
          action_type        & recover(){ return m_recover; }
        private:
          action_type m_recover;

        public:
          protocol_type    const&protocol()const{ return m_protocol; }
          bool                   protocol( protocol_type const& protocol_param ){ m_protocol = protocol_param; return bool( true ); }
          protocol_type        & protocol(){ return m_protocol; }
        private:
          protocol_type m_protocol;

        public:
          bool view
           (
             structure_type const&   struct_param
            ,output_type         &   output_param
           )const
           {
            for( auto const& item : struct_param.container() )
             {
              property_type const*  property = item.second.get();
              category_type const* category = dynamic_cast< category_type const* >( property );

              if( nullptr != category )
               {
                auto const& action = protocol().find( category->type() );
                if( protocol().end() == action )
                 {
                  goto label_recover;
                 }

                if( false == action->second( item.first, *property, output_param ) )
                 {
                  goto label_recover;
                 }
               }

              continue;
              label_recover:
               if( false == recover()( item.first, *property, output_param ) )
                {
                 return false;
                }
             }

            return true;
           }

     };

   }
 }

#endif
