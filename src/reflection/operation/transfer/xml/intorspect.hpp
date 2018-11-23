#ifndef reflection_operation_transfer_xml_introspect
#define reflection_operation_transfer_xml_introspect

// ::reflection::operation::transfer::xml_class<output_name,key_name,type_name>

#include "../../../content/inspect/inspect.hpp"
#include "../../../content/category.hpp"
#include "../../../content/function/algorithm.hpp"
#include "../../../content/typedef/typedef.hpp"
#include "../../../content/enum/enum.hpp"
#include "../../../property/structure.hpp"
#include "../../../operation/transfer/observe.hpp"





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
           typename      output_name
          ,typename         key_name = std::string
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
         struct introspect_struct
            {
           public:
             typedef      output_name        output_type;
             typedef         key_name           key_type;
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

           public:
             typedef std::size_t size_type;
             typedef std::string string_type;

             typedef struct context_struct
              {
               public:
                size_type m_ident=0;
                string_type m_element="e";
                string_type m_item="i";
                string_type m_type="t";
                string_type m_name="n";
                string_type m_note="m";
                string_type m_message="m";
                string_type m_accessibility="a";
                string_type m_linkage="a";

                void inc(){ ++m_ident; }
                void dec(){ --m_ident; }
                size_type const& get()const{ return m_ident; }
                void newl( output_type & output_param ){ output_param << std::endl; for( size_type i=0; i< this->get(); ++i ) output_param <<  "  "; }
              }context_type;

             typedef std::shared_ptr< context_type > contextPtr_type;

           public:
             static contextPtr_type context(){ return std::make_shared<context_struct>(); }

           public:
             typedef ::reflection::operation::transfer::xml::introspect_struct<output_name,key_name,identifier_name, report_name, container_name> this_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;
             typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

             typedef typename std::add_const< property_type >::type                          property_qualified_type;
             typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

             typedef  ::reflection::operation::transfer::observe_class< output_type, key_type, identifier_type, report_type, std::add_const, container_name > observe_type;

           public:
             typedef ::reflection::property::enumeration::pure_class<identifier_type,size_type>           enumeration_type;
             typedef ::reflection::content::function::algorithm_class<identifier_type>                      algorithm_type;
             typedef ::reflection::property::typedefinition::pure_class< identifier_type >             typedefinition_type;

           public:
             explicit introspect_struct( observe_type & observe_param, contextPtr_type context_param = this_type::context() )
              {
               using namespace std::placeholders;

               observe_param.control( observe_type::stage_introductum_index,   std::bind( &this_type::introductum, context_param, _1, _2, _3 ) );

               observe_param.control( observe_type::stage_prefix_index,         std::bind( &this_type::prefix, context_param, _1, _2, _3 )      );
               observe_param.control( observe_type::stage_suffix_index,         std::bind( &this_type::suffix, context_param, _1, _2, _3 )     );

               observe_param.control( observe_type::stage_conclusio_index ,    std::bind( &this_type::conclusio, context_param, _1, _2, _3 )   );

                observe_param.insert( identificator_type::template get<     enumeration_type >(), std::bind( &this_type::enumeration,    context_param, _1, _2, _3 ) );
                observe_param.insert( identificator_type::template get<       algorithm_type >(), std::bind( &this_type::function,       context_param, _1, _2, _3 ) );
                observe_param.insert( identificator_type::template get<  typedefinition_type >(), std::bind( &this_type::typedefinition, context_param, _1, _2, _3 ) );

              }

           private:
             typedef    std::wstring     wstring_type;
             typedef    bool             boolean_type;

             static report_type recover(     contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               output_param << "<" << context_param->m_note << " message=\"Continue like nothing happen.\" /> ";
               return report_type( true );
              }

             static report_type introductum( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->newl( output_param );
               output_param <<  "<"<< context_param->m_element << ">" ;
               context_param->inc();
               return report_type( true );
              }

             static report_type conclusio (  contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec();
               output_param <<  "</"<< context_param->m_element <<">" ;
               context_param->newl( output_param );
               return report_type( true );
              }

             static report_type prefix(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->newl( output_param );
               output_param << "<" << context_param-> m_item << " ";
               context_param->inc();

               if( key_type{} != key_param ) output_param << context_param-> m_name << "=\"" << key_param << "\" ";

               decoration_category( context_param, output_param, property_param );
               decoration_accessibility(           output_param, property_param );
               decoration_linkage(                 output_param, property_param );
               decoration_qualification(           output_param, property_param );
               decoration_derivation(              output_param, property_param );
               decoration_relation(                output_param, property_param );

               output_param << ">";
               return report_type( true );
              }

             static report_type suffix(      contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               context_param->dec(); //context_param->newl( output_param );
               output_param << "</"<< context_param->m_item << ">";
               return report_type( true );
              }

             static report_type stasimon( output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               return report_type( true );
              }

             static report_type decoration_category( contextPtr_type const&context_param, output_type & output_param, property_qualified_reference_type property_param)
              {
               category_type const* category = dynamic_cast< category_type const* >( &property_param );
               if( nullptr != category )
                {
                 output_param << "" << context_param->m_type << "=\"" << category->identifier() << "\" ";
                 return report_type( true );
                }
               else
                {
                 output_param << context_param->m_note<<  "=\"Can not detect type\" ";
                 return report_type( false );
                }
               return report_type( false );
              }

             static void decoration_accessibility(                             output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::accessibility_class accessibility_type;
               accessibility_type  const* accessibility = dynamic_cast< accessibility_type const* >( &property_param );
               if( nullptr == accessibility )
                {
                 return;
                }
               switch( accessibility->accessibility() )
                {
                 default:
                 case( accessibility_type::public_index    ): output_param << " accessibility="<< "\"public\"" ;    break;
               //case( accessibility_type::gloabal_index   ): output_param << " accessibility="<< "\"global\"";    break;
                 case( accessibility_type::protected_index ): output_param << " accessibility="<< "\"protected\""; break;
                 case( accessibility_type::private_index   ): output_param << " accessibility="<< "\"private\"" ;   break;
               //case( accessibility_type::unknown_index   ): output_param << " accessibility="<< "\"unknown\"" ;   break;
                }

               output_param << " ";
              }

             static void decoration_linkage(                                   output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::linkage_class linkage_type;
               linkage_type  const* linkage = dynamic_cast< linkage_type const* >( &property_param );
               if( nullptr == linkage )
                {
                 return;
                }
               switch( linkage->linkage() )
                {
                 case( linkage_type::inline_index    ): output_param << " linkage="<< "\"inline\"" ;    break;
                 case( linkage_type::static_index    ): output_param << " linkage="<< "\"static\"" ;    break;
               //case( linkage_type::extern_index    ): output_param << " linkage="<< "\"extern\"" ; break;
               //case( linkage_type::dll_index       ): output_param << " linkage="<< "\"dll\"" ;   break;
               //case( linkage_type::default_index   ): output_param << " linkage="<< "\"default\"" ;   break;
                }
               output_param << " ";
              }

             static void decoration_qualification( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::qualification_class qualification_type;
               qualification_type  const* qualification = dynamic_cast< qualification_type const* >( &property_param );
               if( nullptr == qualification )
                {
                 return;
                }
               if( qualification->qualification() & qualification_type::const_index )
                {
                 output_param << "    qualification="<< "\"const\" " ;
                }

               if( qualification->qualification() & qualification_type::volatile_index )
                {
                 output_param << "    qualification="<< "\"volatile\" ";
                }

               //switch( qualification->qualification() )
                {
               //case( qualification_type::extern_index    ): output_param << "    \"qualification\": "<< "\"extern\""<< ","  <<std::endl; break;
               //case( qualification_type::dll_index       ): output_param << "    \"qualification\": "<< "\"dll\""<< "," <<std::endl;   break;
               //case( qualification_type::default_index   ): output_param << "    \"qualification\": "<< "\"default\""<< "," <<std::endl;   break;
                }
              }

             static void decoration_derivation( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::derivation_class derivation_type;
               derivation_type  const* derivation = dynamic_cast< derivation_type const* >( &property_param );
               if( nullptr == derivation )
                {
                 return;
                }
               switch( derivation->derivation() )
                {
                 case( derivation_type::virtual_index   ): output_param << "derivation= "<< "\"virtual\""; break;
                }
               output_param << " ";
              }

             static void decoration_relation( output_type & output_param, property_qualified_reference_type property_param)
              {
               typedef ::reflection::ornament::relation_class relation_type;
               relation_type  const* relation = dynamic_cast< relation_type const* >( &property_param );
               if( nullptr == relation )
                {
                 return;
                }
               switch( relation->relation() )
                {
                 case( relation_type::member_index   ): output_param << "relation="<< "\"member\"" ; break;
                 case( relation_type::base_index     ): output_param << "relation="<< "\"base\""   ; break;
                 case( relation_type::friend_index   ): output_param << "relation="<< "\"friend\"" ; break;
                }
               output_param << " ";
              }

            public:

             static report_type   enumeration    ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               enumeration_type  const* enum_instance = dynamic_cast< enumeration_type const* >( &property_param );
               if( nullptr == enum_instance )
                {
                 output_param << "< note=\"Wrong type supplied.\" /> ";
                 return report_type( false );
                }

               context_param->inc();
               context_param->newl( output_param );
               for( std::size_t index=0; index < enum_instance->container().size(); ++index )
                {
                 output_param << "<parameter ";
                 output_param << "ordinal=\"" << index << "\" ";
                 output_param << "value=\""   << enum_instance->container()[index].value() << "\" ";
                 output_param << "name=\""    << enum_instance->container()[index].name()  << "\" ";
                 output_param << "/>";
                 if( index +1 < enum_instance->container().size()) { context_param->newl( output_param ); }
                }
               context_param->dec();
               context_param->newl( output_param );

               return report_type( true );
              }

             static report_type   function       ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               algorithm_type  const* function_instance = dynamic_cast< algorithm_type const* >( &property_param );
               if( nullptr == function_instance )
                {
                 output_param << "< note=\"Wrong type supplied.\" /> ";
                 return report_type( false );
                }

               context_param->inc(  ); context_param->newl( output_param );
               for( std::size_t index=0; index < function_instance->signature().size(); ++index )
                {
                 if( function_instance->signature()[index].original()  == identificator_type::NAT() )
                  {
                   continue;
                  }

                 output_param << "<parameter ";
                 output_param << "ordinal=\"" << index << "\" ";
                 output_param << "type=\"" << function_instance->signature()[index].original()  << "\" ";
                 output_param << "/>";
                 context_param->newl( output_param );
                }
               context_param->dec(  );
               context_param->newl( output_param );

               return report_type( true );
              }

             static report_type   typedefinition ( contextPtr_type &context_param, output_type & output_param, key_type const& key_param, property_qualified_reference_type property_param )
              {
               typedefinition_type  const* typedef_instance = dynamic_cast<         typedefinition_type const* >( &property_param );
               if( nullptr == typedef_instance )
                {
                 output_param << "<note=\"Wrong type supplied.\" .>";
                 return report_type( false );
                }

               context_param->newl( output_param ); output_param << "<name   value=\"" << typedef_instance->name() << "\" />";
               context_param->newl( output_param ); output_param << "<object value=\"" << typedef_instance->object() << "\" />";

               return report_type( true );
              }

         };

       }
     }
   }
 }

#endif
