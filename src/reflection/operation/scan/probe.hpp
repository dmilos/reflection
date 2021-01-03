#ifndef reflection_operation_scan_probe
#define reflection_operation_scan_probe

// ::reflection::operation::scan::probe_class< input_name, identifier_name, report_name >


namespace reflection
 {
  namespace operation
   {
    namespace scan
     {

      template
       <
         typename       input_name
        ,typename  identifier_name = std::string
        ,typename      report_name = bool
       >
       class probe_class
        {
         public:

           typedef  identifier_name     identifier_type;
           typedef  input_name          input_type;
           typedef  report_name         report_type;

           typedef ::reflection::property::pure_class     property_type;
           typedef ::std::shared_ptr<property_type>       property_pointer_type;

         public:
           probe_class(){ }
           virtual ~probe_class(){ }

         public:
           virtual report_type poke( identifier_type & indetifier_param, input_type & input_param )=0;
           virtual report_type skip( input_type & input_param ) =0;
           virtual report_type  eof( input_type & input_param ) =0;
           virtual void        push( ) =0;
           virtual void         pop( ) =0;
       };

     }
   }
 }

#endif
