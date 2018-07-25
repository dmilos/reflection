#ifndef reflection_content_exposed_member_hpp
#define reflection_content_exposed_member_hpp
 // ::reflection::content::exposed::member_class<data_name>
 // ::reflection::content::exposed::member( )

#include "../direct/member.hpp"
#include "../mutate/member.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace exposed
     {

      template
       <
         typename data_name
        ,typename original_name  //= data_name const&
        ,typename model_name  //= data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       struct member_struct
        : public ::reflection::content::direct::member_struct< data_name,original_name,class_name,storage_name>
        , public ::reflection::content::mutate::member_struct< data_name,model_name,class_name,storage_name, report_name >
        {
         public:
           typedef      data_name     data_type;
           typedef  original_name    model_type;
           typedef     model_name    image_type;
           typedef     class_name    class_type;
           typedef   storage_name  storage_type;

           typedef ::reflection::content::direct::member_struct< data_name,original_name,class_name,storage_name>  direct_type;
           typedef ::reflection::content::mutate::member_struct< data_name,model_name,class_name,storage_name >   mutate_type;

           typedef typename direct_type::traitor_type       traitor_type;
           typedef typename direct_type::extractor_type  extractor_type;

           typedef typename mutate_type::writter_type      writter_type;
           typedef typename mutate_type::assigner_type    assigner_type;

           typedef ::reflection::content::exposed::basic_class<data_name,original_name,model_name,storage_type, extractor_type, assigner_type> typedef_type;

           static typedef_type make( storage_type const& storage_param, traitor_type const& traitor_param, writter_type const& writter_param  )
            {
             return typedef_type( storage_param, extractor_type(traitor_param), assigner_type(writter_param) );
            }
        };

      /*template
       <
       >
       struct member_struct<void>
        //: S_storage::GC_member<data_name>::T_direct
        {
         //! @todo
         //typedef void     data_type;

         //static typedef_type make( void ){ return typedef_type(); }
        };*/

      template
       <
         typename data_name
        ,typename original_name
        ,typename model_name  //= data_name const&
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::exposed::member_struct<data_name,original_name,model_name,class_name,storage_name>::typedef_type
       member
        (
          storage_name     const&             storage_param
         ,original_name    (class_name::*traitor_param )( void )
         ,model_name       (class_name::*writter_param )()const//!< <data_name,model_name,class_name,storage_name>::T_traitor const& writter_param
        )
        {
         typedef ::reflection::content::exposed::member_struct<data_name,original_name,model_name,class_name,storage_name> member_type;
         return member_type::make( storage_param, traitor_param, writter_param );
        }


      template
       <
        typename data_name
       ,typename class_name
       ,typename storage_name
       >
       inline
       typename ::reflection::content::exposed::member_struct<data_name,data_name &,data_name const&,class_name,storage_name>::typedef_type
       member
        (
          storage_name   const &             storage_param
         ,data_name            &    (class_name::*traitor_param )( void )
         ,data_name       const&    (class_name::*writter_param  )()const               //!< <data_name,model_name,class_name,storage_name>::T_traitor const& writter_param
        )
        {
         typedef ::reflection::content::exposed::member_struct<data_name,data_name &,data_name const&,class_name,storage_name> member_type;
         return  member_type::make( storage_param, traitor_param, writter_param );
        }


     }
   }
 }

#endif
