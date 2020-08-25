#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_process
#define reflection_operation_transfer_python_bind_process

// ::reflection::operation::transfer::python::bind_class<output_name,key_name,type_name>

#include "../../../content/category.hpp"

#include "../../../ornament/linkage.hpp"
#include "../../../ornament/kind.hpp"

#include "../../../content/function/algorithm.hpp"
#include "../../../content/typedef/typedef.hpp"
#include "../../../content/enum/enum.hpp"

#include "../../../property/structure.hpp"
#include "../../../operation/transfer/observe.hpp"

#include "./output.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace python
       {
        namespace bind
         {

        template
         <
           typename         key_name = std::string
          ,typename  identifier_name = std::string  //!<  Specific for this type of transfer
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct process_struct
          {
           public:
           //typedef     <class-specific>    output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type; //!<
             typedef      report_name        report_type;

             typedef ::reflection::operation::transfer::python::bind::process_struct<key_name,identifier_name, report_name, container_name> this_type, process_type;
             typedef ::reflection::operation::transfer::python::bind::output_class output_type;

           public:
             typedef std::size_t size_type;
             typedef std::string string_type;

             typedef struct context_struct
              {
               public:
                 context_struct( )
                  {
                  }
               public:
                 string_type m_present_prefix;
                 string_type m_present_sufix;
                 string_type m_process_prefix;
                 string_type m_process_sufix;
                 string_type m_disclose_prefix;
                 string_type m_disclose_sufix;
               private:
                 identifier_type m_identifier;
                 typename output_type::typeObject_type *  m_current;
                 std::vector<string_type> m_space;
                 void increase( string_type const& space ){ m_space.push_back( m_space ); }
                 void decrease(){ m_space.pop_back(); }
                 friend struct process_type;
              }context_type;

           public:
             typedef std::shared_ptr< context_type > contextPtr_type, context_pointer_type;
             static contextPtr_type context(){ return std::make_shared<context_type>(); }

           public:
             typedef ::reflection::operation::transfer::python::bind::process_struct<key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>   enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit process_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               using namespace std::placeholders;
               observe_param.control( observe_type::stage_introductum_index,        std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_exodus_index,        std::bind( &this_type::exodus, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_prolog_index,   std::bind( &this_type::prolog, context_param, _1, _2, _3 ) );
               observe_param.control( observe_type::stage_epilog_index,     std::bind( &this_type::epilog  , context_param, _1, _2, _3 ) );

               observe_param.control( observe_type::recover_action_acquisition_index,  std::bind(    &this_type::recover, context_param, _1, _2, _3 ) );

               observe_param.insert( identificator_type::template get<     enumeration_type  >(), std::bind( &this_type::enumeration   , context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<       algorithm_type  >(), std::bind( &this_type::function      , context_param, _1, _2, _3 ) );
               observe_param.insert( identificator_type::template get<  typedefinition_type  >(), std::bind( &this_type::typedefinition, context_param, _1, _2, _3 ) );
              }

           private:
             //typedef    std::wstring     wstring_type;
             //typedef    bool             boolean_type;

             typedef ::reflection::ornament::linkage_class linkage_type;
             typedef ::reflection::ornament::relation_class relation_type;
             typedef ::reflection::ornament::kind_class kind_type;
             typedef ::reflection::ornament::category_class<identifier_type>     category_type;

             static report_type recover(          contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               if( kind_type::data_index == kind_type::kind( property_param ) )
                {
                 return report_type( true );
                }

               if( relation_type::base_index == relation_type::relation( property_param ) )
                {
                 auto const& identifier_item = category_type::identifier( property_param );
                 std::cout << "Base type: "<<  identifier_item << std::endl;
                 output_param.geneaology().relate( context_param->m_current->identifier(), identifier_item,  relation_type::derived_index );
                 output_param.geneaology().relate( identifier_item, context_param->m_current->identifier(),  relation_type::base_index    );
                }

               return report_type( true );
              }

             static report_type introductum(           contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //output_param.clear();
               std::cout << "-- {[(" <<  category_type::identifier( property_param )  << ")]}" << std::endl;
               std::cout << "-- {[(" <<  key_param  << ")]}" << std::endl;

               context_param->m_identifier = category_type::identifier( property_param );
               output_param.appendType( context_param->m_identifier, typename output_type::typeObject_type{} );
               context_param->m_current = const_cast<typename output_type::typeObject_type * >( &( output_param.typeObject().find( context_param->m_identifier )->second) );
               return report_type( true );
              }

             static report_type exodus(           contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //Py_InitModule( output_param.module_name().c_str(), output_param.m_method.data() );
               context_param->m_identifier =  identificator_type::NAT();
               return report_type( true );
              }

             static report_type prolog(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               report_type result = true;

               //TODO output_param <<  "class";

               //TODO output_param << std::endl;

               //TODO output_param <<  "  {" << std::endl;
               return result;
              }

             static report_type epilog (       contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               //TODO output_param <<  "  };" << std::endl;
               return report_type( true );
              }

             static report_type enumeration(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* enum_instance = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == enum_instance )
                {
                 return report_type( false );
                }

               std::cout << "enum: " << key_param ;
               //// TODO output_param << "enum "<< enum_instance->name() <<" { ";

               for( std::size_t index=0; index < enum_instance->container().size(); ++index )
                {
                 output_param.interface().appendConst( enum_instance->container()[index].name(), (int)enum_instance->container()[index].value() );
                }

               std::cout << std::endl ;
               return report_type( true );
              }

             static PyObject * function_member_executor( PyObject *self, PyObject *args )
              {
               std::cout << "pointer: " << (void*)self << std::endl;
                if( nullptr != self )
                 {
                  //std::cout << "type:     " <<       self->ob_type << std::endl;
                  //std::cout << "refcount: " <<       self->ob_refcnt<< std::endl;
                 }

               return Py_BuildValue( "i", 10 );
              }

             static PyObject * function_executor( PyObject *self, PyObject *args )
              {
               std::cout << "pointer: " << (void*)self << std::endl;
                if( nullptr != self )
                 {
                  //std::cout << "type:     " <<       self->ob_type << std::endl;
                  //std::cout << "refcount: " <<       self->ob_refcnt<< std::endl;
                 }

               return Py_BuildValue( "i", 10 );
              }

             static report_type function (        contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               std::cout << key_param << std::endl;
               if( linkage_type::static_index == linkage_type::linkage( property_param ) )
                {
                 context_param->m_current->interface().appendMethod( key_param, function_member_executor, METH_VARARGS, "Execute a static member function." );
                 output_param.interface().appendMethod( key_param, function_executor, METH_VARARGS, "Execute a static member function." );
                 return report_type( true );
                }
               context_param->m_current->interface().appendMethod( key_param, function_member_executor, METH_VARARGS, "Execute a member function." );

               return report_type( true );

               algorithm_type  const* function_instance = dynamic_cast< algorithm_type const* >( &property_param );
               if( nullptr == function_instance )
                {
                 return report_type( false );
                }

               for( std::size_t index=0; index < function_instance->signature().size(); ++index )
                {
                 if( function_instance->signature()[index].original() ==  identificator_type::NAT() )
                  {
                   continue;
                  }

                 std::cout << function_instance->signature()[index].original() << " " ;
                }
               std::cout << key_param << " ); ";

               std::cout << std::endl;
               return report_type( true );
              }

             static report_type typedefinition (  contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedefinition_type  const* typedef_instance = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == typedef_instance )
                {
                 return report_type( false );
                }

               //output_param << "typedef  " << typedef_instance->object() << "  "<< typedef_instance->name();

               return report_type( true );
              }

         };

         }
       }
     }
   }
 }

#endif
#endif
