#ifndef reflection_property_mutate_member
#define reflection_property_mutate_member

// ::reflection::property::mutate::member_struct<model_name,class_name,carrier_name,report_name>

#include "../../ornament/visibility.hpp"
#include "../../ornament/relation.hpp"
#include "./base.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
      {
       namespace _internal
        {

         template
          <
           typename model_name
          ,typename class_name
          ,typename storage_name
          ,typename report_name
          >
         struct  member_struct
          {
           typedef model_name    model_type;
           typedef class_name    class_type;
           typedef storage_name  storage_type;
           typedef report_name   report_type;

           typedef       report_type       (class_name::*writer_type)( model_type );

           typedef class assigner_class
            {
             public:
               typedef model_name    model_type,    T_2nd;
               typedef storage_name  storage_type;
               typedef report_name   report_type,   T_0th;

               explicit assigner_class( writer_type const& writer_param = NULL )
                :m_writer( writer_param )
                {
                }
               report_type operator()( storage_type & carrier_param, model_type input_param )const
                {
                 return  ( (*carrier_param).*m_writer)( input_param );
                }
             private:
              writer_type  m_writer;
            } assigner_type;

           typedef ::reflection::property::mutate::basic_class <model_name,storage_name,assigner_type,report_name>      typedef_type;

           static typedef_type make( storage_type const& carrier_param, writer_type const& writer_param )
                  {
                   return typedef_type( carrier_param, assigner_type( writer_param ) );
                  }

          };

        }

       template
        <
          typename model_name
         ,typename class_name
         ,typename storage_name
         ,typename report_name
        >
       class  member_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::visibility_class
        , public ::reflection::property::mutate::_internal::member_struct<model_name,class_name,storage_name,report_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::visibility_class visibility_type;

          typedef typename ::reflection::property::mutate::_internal::member_struct<model_name,class_name,storage_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::assigner_type     assigner_type;
          typedef typename basic_type::writer_type         writer_type;
          typedef typename basic_type::storage_type       storage_type;

          explicit member_class( storage_type   const& storage_param, writer_type const& writer_param )
           : relation_type( relation_type::member_index )
           , visibility_type( visibility_type::unknown_index )
           , base_type( storage_param, assigner_type( writer_param ) )
           {
           }

         using base_type::process;
        };

       template
        <
         typename model_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
        >
       inline
       typename ::reflection::property::mutate::member_class<model_name,class_name,storage_name,report_name>
       member
        (
          storage_name const& carrier_param
        , report_name (class_name::*writer_param)( model_name )
        )
        {
         typedef ::reflection::property::mutate::member_class<model_name,class_name,storage_name,report_name> member_type;
         return member_type( carrier_param, writer_param );
        }

     }
   }
 }

#endif
