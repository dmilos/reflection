#ifndef reflection_operation_scan_probe
#define reflection_operation_scan_probe

// ::reflection::operation::scan::probe::pure_class< input_name, identifier_name, report_name >
// ::reflection::operation::scan::probe::base_class< input_name, identifier_name, key_name, report_name >


namespace reflection
 {
  namespace operation
   {
    namespace scan
     {
      namespace probe
       {

        template
         <
           typename       input_name
          ,typename  identifier_name
          ,typename      report_name
         >
         class pure_class
          {
           public:
             typedef  identifier_name     identifier_type;
             typedef  input_name          input_type;
             typedef  report_name         report_type;

           public:
             pure_class(){ }
             virtual ~pure_class(){ }

           public:
             virtual report_type poke( identifier_type & indetifier_param, input_type & input_param )=0;
             virtual report_type skip( input_type & input_param ) =0;
             virtual report_type  eos( input_type & input_param ) =0;
             virtual identifier_type const&   identifier()const=0; //!< last known good identifier
          };

        template
         <
           typename       input_name
          ,typename  identifier_name
          ,typename         key_name
          ,typename      report_name
         >
         class base_class
          : public ::reflection::operation::scan::probe::pure_class< input_name, identifier_name, report_name >
          {
           public:
             typedef  identifier_name     identifier_type;
             typedef  input_name               input_type;
             typedef  key_name                   key_type;
             typedef  report_name             report_type;

           public:
             base_class(){ }
             virtual ~base_class(){ }

           public:
             virtual void             push() =0;
             virtual void              pop() =0;
             virtual key_type const&   key()const=0; //!< last known good key
          };

       }
     }
   }
 }

#endif
