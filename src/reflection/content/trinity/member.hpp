#ifndef reflection_content_trinity_member_hpp
#define reflection_content_trinity_member_hpp
 // ::reflection::content::trinity::member_class<data_name>
 // ::reflection::content::trinity::member( )

#include "../direct/member.hpp"
#include "../mutate/member.hpp"
#include "../inspect/member.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace trinity
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename original_name  //= data_name &
        ,typename model_name     //= data_name const&
        ,typename image_name     //= data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       class member_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::trinity::member_class<original_name, model_name, image_name, class_name, storage_name, report_name >
        {
          typedef identifier_name  identifier_type;
          typedef data_name        data_type;
          typedef original_name    original_type;
          typedef     image_name    image_type;
          typedef class_name       class_type;
          typedef storage_name     storage_type;

         typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
         typedef ::reflection::property::trinity::member_class< original_name, model_name, image_name, class_name, storage_name, report_name  >  member_type;

         using member_type::member_type;
        };

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename original_name  //= data_name &
        ,typename model_name     //= data_name const&
        ,typename image_name     //= data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name = bool
       >
       inline
       ::reflection::content::trinity::member_class< identifier_name, data_name,original_name, model_name, image_name,class_name,storage_name,report_name>
       member
        (
          storage_name  const&             storage_param
         ,original_name  (class_name::*traitor_param)(void )
         ,report_name    (class_name::*writer_param)( model_name )
         ,image_name     (class_name::*reader_param )()const   //!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::trinity::member_class< identifier_name, data_name, data_name &,data_name const&, data_name const&,class_name,storage_name,report_name> member_type;
         return member_type( storage_param, traitor_param, writer_param, reader_param );
        }


      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name = bool
       >
       inline
       typename ::reflection::content::trinity::member_class< identifier_name, data_name,data_name&, data_name const&,data_name const&,class_name,storage_name,report_name>
       member
        (
          storage_name  const&             storage_param
         ,data_name&         (class_name::*traitor_param)( )
         ,report_name        (class_name::*writer_param)( data_name const& )
         ,data_name const&   (class_name::*reader_param )()const               //!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::trinity::member_class< identifier_name, data_name,data_name&, data_name const&,data_name const&,class_name,storage_name,report_name> member_type;
         return member_type( storage_param, traitor_param, writer_param, reader_param );
        }

     }
   }
 }

#endif

