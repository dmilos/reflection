#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_output
#define reflection_operation_transfer_python_bind_output

// ::reflection::operation::transfer::python::bind::output_class

#include <string>

#include "./typeObject.hpp"
#include "./interface.hpp"

#include "../../factory.hpp"

#include "../../../archive/genealogy.hpp"
#include "../../../ornament/relation.hpp"

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

          //template
          // <
          //   typename         string_name = std::string
          // >
          class output_class
           {
            public:
              typedef std::string string_type, identifier_type;
              typedef int            int_type;
              typedef bool       report_type;

            public:
              typedef ::reflection::operation::transfer::python::bind::interface_class    interface_type;
              typedef ::reflection::operation::transfer::python::bind::typeObject_class  typeObject_type;
              typedef ::reflection::operation::transfer::factory_class<identifier_type>         factory_type;
              
              typedef ::reflection::ornament::relation_class         relation_type;
              typedef ::reflection::archive::genealogy_class<identifier_type, relation_type::relation_enum, report_type > geneaology_type;

            public:
             explicit output_class( string_type const& module_name = "spam" )
               :m_module_name( module_name )
               {
                this->clear();
               }

            public:
              string_type const& module_name()const
              {
                return m_module_name;
              }
             void module_name( string_type const& mn )
               {
                m_module_name = mn;
               }
            private:
              string_type m_module_name;

            public:
              void clear()
               {
                this->m_interface.clear();
                this->m_typeObjectContainer.clear();
               }

           public:
             factory_type const& factory()const{ return m_factory; }
             factory_type      & factory()     { return m_factory; }
           private:
             factory_type m_factory;

           public:
             geneaology_type const& geneaology()const{ return m_geneaology; }
             geneaology_type      & geneaology()     { return m_geneaology; }
           private:
             geneaology_type m_geneaology;
             
            public:
                interface_type m_interface;
            public:
              interface_type const& interface()const{ return m_interface; }
              interface_type      & interface()     { return m_interface; }
            public:
              typedef std::map< string_type, typeObject_type > typeObjectContainer_type;

              typeObjectContainer_type const& typeObject()const
               {
                return m_typeObjectContainer;
               }

              typeObjectContainer_type & typeObject()
               {
                return m_typeObjectContainer;
               }

            public:
              void appendType( string_type const& identifier_param, typeObject_type const& object )
              {
                m_typeObjectContainer.emplace( identifier_param, object );
                m_typeObjectContainer.find( identifier_param )->second.identifier( identifier_param );
              }
            private:
              typeObjectContainer_type  m_typeObjectContainer;

           };

         }
       }
     }
   }
 }

#endif
#endif
