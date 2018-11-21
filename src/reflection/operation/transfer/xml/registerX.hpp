#ifndef reflection_operation_transfer_register_hpp
#define reflection_operation_transfer_register_hpp

// ::reflection::operation::transfer::xml::register_class<output_name,key_name,type_name>

#include "./xml.hpp"



namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace xml
       {

        template
         <
           typename data_name
          ,typename view_name
          ,typename      output_name
          ,typename         key_name
          ,typename  identifier_name
          ,typename      report_name
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         void register_class
          (
                     ::reflection::operation::transfer::observe_class< output_name, key_name, identifier_name, report_name, std::add_const, container_name >                 & observer_param
           ,typename ::reflection::operation::transfer::xml_struct<    output_name, key_name, identifier_name, report_name,                 container_name >::contextPtr_type   & context_param
          )
          {
           using namespace std::placeholders;
           typedef ::reflection::operation::transfer::xml_struct<    output_name, key_name, identifier_name, report_name,                 container_name > xml_type;
           typedef ::reflection::operation::transfer::observe_class< output_name, key_name, identifier_name, report_name, std::add_const, container_name > observe_type;

           auto i = xml_type::identificator_type::template get< data_name >();
           auto f = std::bind( &observe_type::template view_custom<data_name, view_name>, std::ref(observer_param) , _1, _2, _3 );
           observer_param.register__any( i , f );
          }

        template
         <
           typename        data_name
          ,typename      output_name
          ,typename         key_name
          ,typename  identifier_name
          ,typename      report_name
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         void register_vector
          (
                     ::reflection::operation::transfer::observe_class< output_name, key_name, identifier_name, report_name, std::add_const, container_name > & observer_param
           ,typename ::reflection::operation::transfer::xml_struct<    output_name, key_name, identifier_name, report_name,                 container_name >::contextPtr_type & context_param
          )
          {
           using namespace std::placeholders;
           typedef ::reflection::operation::transfer::xml_struct<    output_name, key_name, identifier_name, report_name,                 container_name > xml_type;
           auto i = xml_type::identificator_type::template get< std::vector<data_name> >();
           auto f = std::bind( &xml_type::template vector<data_name>, context_param, std::ref(observer_param), _1, _2, _3 );
           observer_param.register__any( i , f );
          }

        template
         <
           typename      enum_name
          ,typename      output_name
          ,typename         key_name
          ,typename  identifier_name
          ,typename      report_name
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         void register_enum
          (
                     ::reflection::operation::transfer::observe_class< output_name, key_name, identifier_name, report_name, std::add_const, container_name > & observer_param
           ,typename ::reflection::operation::transfer::xml_struct<    output_name, key_name, identifier_name, report_name,                 container_name >::contextPtr_type & context_param
          )
          {
           using namespace std::placeholders;
           typedef ::reflection::operation::transfer::xml_struct<    output_name, key_name, identifier_name, report_name,                 container_name > xml_type;
           auto i = xml_type::identificator_type::template get< enum_name >();
           auto f = std::bind( &xml_type::template enumerant<enum_name>, _1, _2, _3 );
           observer_param.register__any( i, f );
          }

       }

     }
   }
 }

#endif
