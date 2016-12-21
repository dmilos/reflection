#ifndef reflection_content_variable_member_hpp
#define reflection_content_variable_member_hpp
 // ::reflection::content::variable::member_class<data_name>
 // ::reflection::content::variable::member( )

#include "../direct/member.hpp"
#include "../inspect/member.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace variable
     {

      template
       <
         typename data_name
        ,typename original_name  //= data_name const&
        ,typename image_name  //= data_name const&
        ,typename class_name
        ,typename storage_name
       >
       struct member_struct
        : public ::reflection::content::direct::member_struct< data_name,original_name,class_name,storage_name>
        , public ::reflection::content::inspect::member_struct< data_name,image_name,class_name,storage_name >
        {
         public:
           typedef      data_name     data_type;
           typedef  original_name    model_type;
           typedef     image_name    image_type;
           typedef     class_name    class_type;
           typedef   storage_name  storage_type;

           typedef ::reflection::content::direct::member_struct< data_name,original_name,class_name,storage_name>  direct_type;
           typedef ::reflection::content::inspect::member_struct< data_name,image_name,class_name,storage_name >   inspect_type;

           typedef typename direct_type::traitor_type       traitor_type;
           typedef typename direct_type::extractor_type  extractor_type;

           typedef typename inspect_type::reader_type        reader_type;
           typedef typename inspect_type::retriever_type  retriever_type;

           typedef ::reflection::content::variable::basic_class<data_name,original_name,image_name,storage_type, extractor_type, retriever_type> typedef_type;

           static typedef_type make( storage_type const& storage_param, traitor_type const& traitor_param, reader_type const& reader_param  )
            {
             return typedef_type( storage_param, extractor_type(traitor_param), retriever_type(reader_param) );
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
        ,typename image_name  //= data_name const&
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::variable::member_struct<data_name,original_name,image_name,class_name,storage_name>::typedef_type
       member
        (
          storage_name     const&             storage_param
         ,original_name    (class_name::*traitor_param )( void )
         ,image_name       (class_name::*reader_param )()const//!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::variable::member_struct<data_name,original_name,image_name,class_name,storage_name> member_type;
         return member_type::make( storage_param, reader_param , reader_param );
        }


      template
       <
        typename data_name
       ,typename class_name
       ,typename storage_name
       >
       inline
       typename ::reflection::content::variable::member_struct<data_name,data_name &,data_name const&,class_name,storage_name>::typedef_type
       member
        (
          storage_name   const &             storage_param
         ,data_name            &    (class_name::*traitor_param )( void )
         ,data_name       const&    (class_name::*reader_param  )()const               //!< <data_name,image_name,class_name,storage_name>::T_traitor const& reader_param
        )
        {
         typedef ::reflection::content::variable::member_struct<data_name,data_name &,data_name const&,class_name,storage_name> member_type;
         return  member_type::make( storage_param, traitor_param, reader_param );
        }


     }
   }
 }

#endif
