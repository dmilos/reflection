#ifndef reflection_content_guarded_member_hpp
#define reflection_content_guarded_member_hpp
 // ::reflection::content::guarded::member_struct<data_name>
 // ::reflection::content::guarded::member( )

#include "../mutate/member.hpp"
#include "../inspect/member.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace guarded
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename model_name  //= data_name const&
        ,typename image_name  //= data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name = bool
       >
       struct member_struct
        : public ::reflection::content::mutate::member_struct< identifier_name, data_name,model_name,class_name,storage_name,report_name >
        , public ::reflection::content::inspect::member_struct< identifier_name, data_name,image_name,class_name,storage_name >
        {
         public:
           typedef    data_name     data_type;
           typedef   model_name    model_type;
           typedef   image_name    image_type;
           typedef   class_name    class_type;
           typedef storage_name  storage_type;
           typedef  report_name   report_type;

           typedef ::reflection::content::mutate::member_struct< identifier_name, data_name,model_name,class_name,storage_name,report_name >  mutate_type;
           typedef ::reflection::content::inspect::member_struct< identifier_name, data_name,image_name,class_name,storage_name >            inspect_type;

           typedef typename mutate_type::writter_type       writter_type;
           typedef typename mutate_type::assigner_type     assigner_type;

           typedef typename inspect_type::reader_type        reader_type;
           typedef typename inspect_type::retriever_type  retriever_type;

           typedef ::reflection::content::guarded::basic_class<identifier_name, data_name,image_name,model_name,storage_type,assigner_type, retriever_type, report_name  > typedef_type;

           static typedef_type make( storage_type const& storage_param, writter_type const& writter_param, reader_type const& reader_param  )
            {
             return typedef_type( storage_param, assigner_type(writter_param), retriever_type(reader_param) );
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
         typename identifier_name
        ,typename       data_name
        ,typename      model_name  //= data_name const&
        ,typename      image_name  //= data_name const&
        ,typename      class_name
        ,typename    storage_name
        ,typename     report_name = bool
       >
       inline
       typename ::reflection::content::guarded::member_struct<data_name,model_name,image_name,class_name,storage_name,report_name>::typedef_type
       member
        (
          storage_name     const&             storage_param
         ,report_name       (class_name::*writter_param)( model_name )
         ,image_name        (class_name::*reader_param )()const//!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::guarded::member_struct<data_name,model_name,image_name,class_name,storage_name,report_name> member_type;
         return member_type::make( storage_param, writter_param, reader_param );
        }

      template
       <
         typename identifier_name
        ,typename       data_name
        ,typename      class_name
        ,typename    storage_name
        ,typename     report_name
       >
       inline
       typename ::reflection::content::guarded::member_struct<identifier_name, data_name, data_name const&, data_name const&,class_name,storage_name,report_name>::typedef_type
       member
        (
          storage_name  const&                  storage_param
         ,report_name             (class_name::*writter_param)( data_name const& )
         ,data_name     const&    (class_name::*reader_param )()const               //!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::guarded::member_struct<identifier_name, data_name,  data_name const&, data_name const&,class_name,storage_name,report_name> member_type;
         return member_type::make( storage_param, writter_param, reader_param );
        }

     }
   }
 }

#endif

