#ifndef reflection_property_mutate_base
#define reflection_property_mutate_base
//

 #include "./_pure.hpp"
#include "../_carrier.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
      {

       template
        <
          typename model_name
         ,typename storage_name  // T_model, T_report, storage_type,   T_report operator()( storage_type &, T_model )
         ,typename assigner_name   //= stl_ext::assign_ref_to_ref< storage_name, model_name >
         ,typename report_name     //= bool
        >
        class base_class
         : virtual public ::reflection::property::mutate::pure_class<model_name,report_name>
         , virtual public ::reflection::property::_internal::carrier_class<storage_name>
         {
          public:

            typedef model_name     model_type;
            typedef storage_name   storage_type;
            typedef assigner_name  assigner_type;
            typedef report_name    report_type;

            typedef ::reflection::property::_internal::carrier_class<storage_name>  carrier_type;

            explicit base_class
                      (
                       assigner_type  const& assigner_param   = assigner_type()
                      )
                      {
                      }

            explicit base_class
                      (
                        storage_type   const& storage_param
                       ,assigner_type  const& assigner_param   = assigner_type()
                      )
                      :carrier_type( storage_param )
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
            report_type       process( model_type model_param )
             {
              return this->assigner()( this->carrier_type::F1_carrier(), model_param );
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
