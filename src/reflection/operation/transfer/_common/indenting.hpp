#ifndef reflection_operation_transfer__common_indenting
#define reflection_operation_transfer__common_indenting

// ::reflection::operation::transfer::_common::indenting_class<output_name, string_name>

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace _common
       {

        template
         <
           typename      output_name
          ,typename      string_name
         >
          struct indenting_class
           {
             typedef std::size_t size_type;
             typedef string_name string_type;
             typedef output_name output_type;
            public:
              size_type   m_depth=0;
              string_type m_tabulator= "    ";

              //indenting_class( string_type const& tab ):m_tabulator(tab){}

            public:
              void inc(){ ++m_depth; }
              void dec(){--m_depth; }
              size_type const& depth()const{ return m_depth; }
              void indent( output_type & output_param )const{ for( size_type i=0; i< this->depth(); ++i ) output_param << m_tabulator; }
              void newl( output_type & output_param )const{ output_param << std::endl; }
           };

       }
     }
   }
 }

#endif
