#ifndef reflection_property_direct_member
#define reflection_property_direct_member

// ::reflection::property::direct::member_struct<original_name,class_name,storage_name>

#include "./basic.hpp"
#include "../../ornament/accessibility.hpp"
#include "../../ornament/relation.hpp"


namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      namespace _internal
       {

        template
         <
           typename original_name    //!< Expect : reference
          ,typename class_name
          ,typename storage_name
         >
         struct member_struct //!< Acces via member function
          {
           typedef original_name original_type; //!< Expect to be reference
           typedef class_name      class_type;
           typedef storage_name  storage_type;

           typedef original_type     (class_name::*traitor_type)(); //!< by design

           typedef class extractor_class
            {
             public:
               explicit extractor_class( traitor_type const& traitor_param = NULL )
                :m_traitor( traitor_param )
                {
                }
               original_type operator()( storage_type & carrier_param )const
                {
                 if( nullptr == m_traitor )
                  {
                   throw (void*)NULL;
                  }
                 if( nullptr == carrier_param )
                  {
                   throw (void*)NULL;
                  }

                 return  ((*carrier_param).*m_traitor)(); //!< By design
                }

             private:
               traitor_type  m_traitor;
            } extractor_type;

           typedef ::reflection::property::direct::basic_class<  original_name, storage_name, extractor_type>      typedef_type;

           static typedef_type make(  storage_type const& carrier_param, traitor_type const& traitor_param )
            {
             return typedef_type( carrier_param, extractor_type( traitor_param ) );
            }
          };

       }

      template
       <
         typename original_name
        ,typename class_name
        ,typename storage_name
       >
       class member_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::property::direct::_internal::member_struct<original_name,class_name,storage_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::direct::_internal::member_struct<original_name,class_name,storage_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type extractor_type;
          typedef typename basic_type::traitor_type     traitor_type;

          typedef typename basic_type::storage_type     storage_type;

          explicit member_class( storage_type   const& storage_param, traitor_type const& traitor_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , base_type( storage_param, extractor_type( traitor_param ) )
            {
            }

          using base_type::disclose;
        };


      template
       <
         typename original_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::direct::member_class<original_name,class_name,storage_name>
       member
        (
          storage_name         const& carrier_param
         ,original_name (class_name::*traitor_param )( void )
        )
        {
         typedef ::reflection::property::direct::member_class<original_name,class_name,storage_name> member_type;
         return member_type( carrier_param, traitor_param );
        }

     }
   }
 }

#endif
