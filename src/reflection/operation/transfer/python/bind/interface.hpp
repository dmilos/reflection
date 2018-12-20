#ifdef Py_PYTHON_H

#ifndef reflection_operation_transfer_python_bind_interface
#define reflection_operation_transfer_python_bind_interface

// ::reflection::operation::transfer::python::bind::interface_class

#include "./instace.hpp"
#include "./memberDef.hpp"
#include "./methodDef.hpp"
#include "./constDef.hpp"

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
          class interface_class
           {
            public:
              typedef std::string string_type;
              typedef int            int_type;

              typedef ::reflection::operation::transfer::python::bind::instance_class  instace_type;

              typedef ::reflection::operation::transfer::python::bind::methodDef_class     methodDef_type;
              typedef ::reflection::operation::transfer::python::bind::memberDef_class     memberDef_type;
              typedef ::reflection::operation::transfer::python::bind::constDef_class       constDef_type;

              typedef  methodDef_type::containerA_type methodDefContainerA_type;
              typedef  methodDef_type::containerX_type methodDefContainerX_type;

              typedef  memberDef_type::containerA_type memberDefContainerA_type;
              typedef  memberDef_type::containerX_type memberDefContainerX_type;

              typedef  constDef_type::containerX_type   constDefContainerX_type;

            public:
              explicit interface_class()
               {
               }

             void syncronize()const
              {
               this->methodDefA();
               this->memberDefA();
               this->constDefX();
              }

            public:
              void clear()
               {
                this->m_methodDefContainerX.clear();
                this->m_memberDefContainerX.clear();
                this->m_constDefContainerX.clear();
               }

            public:
              typedef  ::reflection::operation::transfer::python::bind::methodDef_class    methodDef_type;
              typedef  ::reflection::operation::transfer::python::bind::memberDef_class    memberDef_type;
              typedef  ::reflection::operation::transfer::python::bind::constDef_class      constDef_type;

              typedef  methodDef_type::containerA_type methodDefContainerA_type;
              typedef  methodDef_type::containerX_type methodDefContainerX_type;

              typedef  memberDef_type::containerA_type memberDefContainerA_type;
              typedef  memberDef_type::containerX_type memberDefContainerX_type;

              typedef  constDef_type::containerX_type   constDefContainerX_type;

            public: // Method
              methodDefContainerX_type const& methodDefX()const{ return m_methodDefContainerX; }
              methodDefContainerA_type const& methodDefA()const
               {
                if( false == m_methodDefDirty )
                 {
                  return m_methodDefContainerA;
                 }
                m_methodDefDirty = false;
                methodDef_type::syncronize( m_methodDefContainerA, m_methodDefContainerX );
                return m_methodDefContainerA;
               }

            public:
              void appendMethod( string_type const& name, PyCFunction const& cFunction, int flags, string_type const& doc )
               {
                m_methodDefDirty = true;
                m_methodDefContainerX.emplace_back( name, cFunction, flags, doc );
               }
            private:
              mutable bool                      m_methodDefDirty;
              mutable methodDefContainerA_type  m_methodDefContainerA;
                      methodDefContainerX_type  m_methodDefContainerX;

            public: // Member
              memberDefContainerX_type const& memberDefX()const{ return m_memberDefContainerX; }
              memberDefContainerA_type const& memberDefA()const
               {
                if( false == m_memberDefDirty )
                 {
                  return m_memberDefContainerA;
                 }
                m_memberDefDirty = false;
                memberDef_type::syncronize( m_memberDefContainerA, m_memberDefContainerX );
                return m_memberDefContainerA;
               }

            public:
              void appendMember( string_type const& name, int type, Py_ssize_t const& offset, int flags, string_type const& doc )
               {
                m_memberDefDirty = true;
                m_memberDefContainerX.emplace_back( name, type, offset, flags, doc );
               }
            private:
              mutable bool                      m_memberDefDirty;
              mutable memberDefContainerA_type  m_memberDefContainerA;
                      memberDefContainerX_type  m_memberDefContainerX;

            public:
              void syncronize()
               {
                memberDef_type::syncronize( m_memberDefContainerA, m_memberDefContainerX );
                methodDef_type::syncronize( m_methodDefContainerA, m_methodDefContainerX );
               }

            public:
              constDefContainerX_type const& constDefX()const
               {
                return m_constDefContainerX;
               }
            public:
              void appendConst( string_type const& name , int_type const& value )
              {
                m_constDefContainerX.emplace_back( name, value );
              }
            private:
              constDefContainerX_type  m_constDefContainerX;
           };

         }
       }
     }
   }
 }

#endif
#endif
