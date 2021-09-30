#ifndef reflection_operation_transfer_protobuf_print
#define reflection_operation_transfer_protobuf_print

// ::reflection::operation::transfer::protobuf_class<output_name,key_name,type_name>

#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../content/typedef/typedef.hpp"
#include "../../../content/enum/enum.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/encode/observe.hpp"





namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace protobuf
       {

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct print_struct
          {
          private:
            typedef std::size_t size_type;
            struct context_struct
             {
               size_type m_depth=0;
               void inc(){ ++m_depth; while( m_counter.size() <= m_depth ) m_counter.push_back( 1 ); }
               void dec(){ --m_depth; }
               size_type const& get(){ return m_counter[m_depth]; }
               void next(){ m_counter[m_depth]++; }
               std::vector<size_type> m_counter;
              };

           public:
             typedef std::shared_ptr< context_struct > context_pointer_type;
           public:
             static context_pointer_type context(){ return std::make_shared<context_struct>(); }

           public:
             typedef      output_name        output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

             typedef ::reflection::operation::transfer::protobuf::print_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::encode::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit print_struct( observe_type & observe_param, context_pointer_type context_param = this_type::context() )
              {
               using namespace std::placeholders;
               observe_param.recover( observe_type::recover_type_acquisition_index  , &this_type::recover );
               observe_param.recover( observe_type::recover_action_acquisition_index, &this_type::recover );
               observe_param.recover( observe_type::recover_action_fail_index   , &this_type::recover );

               auto internal = std::make_shared<context_struct>( );

               observe_param.stage( observe_type::stage_prolog_index,   std::bind( &this_type::prolog, internal, _1, _2, _3 )  );
               observe_param.stage( observe_type::stage_epilog_index,    std::bind( &this_type::epilog,  internal, _1, _2, _3 ) );
               observe_param.stage( observe_type::stage_prefix_index,    std::bind( &this_type::prefix,  internal, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<  enumeration_type     >(), &this_type::enumeration    );
               //if(false)observe_param.insert( identificator_type::template get<  algorithm_type               >(), &this_type::function       );
               if(false)observe_param.insert( identificator_type::template get<          typedefinition_type  >(), &this_type::typedefinition );

              }

           private:
             typedef    std::string       string_type;
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //output_param << "; // Continue like nothing happen." << std::endl;

               return report_type( true );
              }

             static report_type prolog( context_pointer_type internal, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;
               output_param <<  "message ";
               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  output_param <<"    "<< category->identifier() << " ";
                  result = true;
                 }
                else
                 {
                  output_param << " //! Can not detect type ";
                  result = false;
                 }
               }
               //output_param << std::endl;

               output_param <<  "  {" << std::endl;

               internal->inc();
               return result;
              }

             static report_type epilog ( context_pointer_type internal, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               internal->dec();
               output_param <<  "}" << std::endl;
               return report_type( true );
              }

             static report_type prefix( context_pointer_type internal, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;

               {
                category_type const* category = dynamic_cast< category_type const* >( &property_param );
                if( nullptr != category )
                 {
                  if( category->identifier() == identificator_type::template get<  algorithm_type      >()  ) return report_type( true );
                  if( category->identifier() == identificator_type::template get<  typedefinition_type >()  ) return report_type( true );
                  if( category->identifier() == identificator_type::template get<  enumeration_type    >()  ) return report_type( true );

                  output_param <<"    required "<< category->identifier() << "  "<< key_param << "  " << " = " << internal->get() << " ; " << std::endl;
                  result = true;
                 }
                else
                 {
                  output_param << " //! Can not detect type ";
                  result = false;
                 }
               }
               internal->next();
               return report_type( result );
              }

             static report_type enumeration( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* context = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == context )
                {
                 output_param << "// < note=\"Wrong type supplied.\" /> ";
                 return report_type( false );
                }

               //output_param <<  key_param;
               output_param << "    enum "<< context->name() <<" { " << std::endl;

               for( std::size_t index=0; index < context->container().size(); ++index )
                {
                 output_param << "        ";
                 output_param << context->container()[index].name()  << " =  ";
                 output_param << context->container()[index].value() ;
                 if( index +1 < context->container().size() ) output_param << ",";
                 output_param << std::endl;

                }
               output_param << "    } ";

               output_param << std::endl;

               return report_type( true );
              }

             static report_type typedefinition ( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
                       typedefinition_type  const* context = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == context )
                {
                 output_param << "<note=\"Wrong type supplied.\" .>";
                 return report_type( false );
                }

               output_param << "typedef  " << context->object() << "  "<< context->name();

               //output_param << std::endl;
               return report_type( true );
              }
          };

       }
     }
   }
 }

#endif
