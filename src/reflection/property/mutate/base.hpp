#ifndef reflection_property_mutate_base
#define reflection_property_mutate_base
//

 #include "./_pure.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
      {

       template
        <
          typename model_name
         ,typename carrier_name  // T_model, T_report, carrier_type,   T_report operator()( carrier_type &, T_model )
         ,typename assigner_name   //= stl_ext::assign_ref_to_ref< carrier_name, model_name >
         ,typename report_name     //= bool
        >
        class base_class
         : virtual public ::reflection::property::mutate::pure_class<model_name,report_name>
         {
          public:

            typedef model_name     model_type;
            typedef carrier_name   carrier_type;
            typedef assigner_name  assigner_type;
            typedef report_name    report_type;

            explicit base_class
                      (
                       assigner_type  const& assigner_param   = assigner_type()
                      ):m_assigner( assigner_param )
                      {
                      }

            explicit base_class
                      (
                        carrier_type   const& carrier_param
                       ,assigner_type  const& assigner_param   = assigner_type()
                      )
                      : m_carrier( carrier_param )
                      ,m_assigner( assigner_param )
                      {
                       //std::cout << __FUNCTION__ << std::endl;
                      }

                    ~base_class( void ){ }

                    /*
                     base_class&
                     operator=( base_class const& original )
                      {
                       std::cout << typeid(*this).name()<<"::"<< __FUNCTION__ << std::endl;
                       assigner( original.assigner() );
                       return *this;
                      }
                    */

          public:
            carrier_type   const&  carrier ( void )const
             {
              return m_carrier; 
             }
            void                carrier( carrier_type const& carrier_param )
             {
              m_carrier = carrier_param;  
             }
          protected:
            carrier_type&          F1_carrier()
             {
              return m_carrier; 
             }
          private:
            carrier_type           m_carrier;

          public:
            report_type       process( model_type model_param )
             {
              return assigner()( F1_carrier(), model_param );
             }

          public:
            assigner_type const&    assigner()const{ return m_assigner; }
            void                    assigner( assigner_type const& assigner_param ){ m_assigner = assigner_param; }

          protected:
            assigner_type      &    F1_assigner(){ return m_assigner; }
          private:
            assigner_type           m_assigner;
         };

      }
    }
  }

#endif
