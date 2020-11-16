#ifndef reflection_operation_scan_sentinel
#define reflection_operation_scan_sentinel

// ::reflection::operation::scan::sentinel_class< pile_name, input_name, report_name >


namespace reflection
 {
  namespace operation
   {
    namespace scan
     {

      template
       <
         typename     pile_name
        ,typename     input_name
        ,typename   report_name = bool
       >
       class sentinel_class
        {
         public:
           typedef  pile_name             pile_type;
           typedef  input_name           input_type;
           typedef  report_name         report_type;

         public:
           sentinel_class(){ }
           virtual ~sentinel_class(){ }

         public:
           virtual report_type prepare( pile_type& pile_param, input_type & input_param ) const=0;
           virtual report_type clean(   pile_type& pile_param, input_type & input_param ) const=0;
           virtual report_type finish(  pile_type& pile_param, input_type & input_param ) const=0;
       };

     }
   }
 }

#endif
