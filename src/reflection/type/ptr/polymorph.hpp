#ifndef reflection_type_ptr_clone
#define reflection_type_ptr_clone

// memory::pointer::polymorph<type_name, duplicator_name>

 #include "./base.hpp"

 namespace memory
  {
   namespace pointer
    {

//#ifdef __GNUC__
// #define TEMPLATE template
//#else
// #define TEMPLATE
//#endif

       template
        <
          typename type_name
         //,typename duplicator_name // = S_DDMRM::S_memory::S_functor::S_duplicator::GC_basic< type_type, bool >
        >
        class polymorph
         : public ::memory::pointer::base<type_name>
          {
          public:
            typedef type_name    type_type;
            //typedef duplicator_name  duplicator_type;

            typedef type_type  *raw_type;

            typedef ::memory::pointer::base<type_name>     base_type;

            typedef polymorph<type_type>   polymorph_type, T_this;

            using base_type::get;
            using base_type::F1_get;
            using base_type::F1_reset;
            using base_type::release;

            polymorph( void )
             :base_type( NULL )
             {
             }

            polymorph( polymorph_type const& original_param )
             //: m_duplicator( original_param.m_duplicator )
             :base_type( NULL )
             {
              //m_duplicator.Fv_process( &F1_get(), original_param.Fv_get() );
             }

            explicit polymorph( void * P_void )
             :base_type( NULL )
             {
             }

            template< typename derive_name >
             explicit polymorph( derive_name * derive_param )
              :base_type( derive_param )
              {
               //m_duplicator.TEMPLATE operator()<derive_name>( NULL , reinterpret_cast<derive_name*>( NULL ) ); //! reconfiguration request
              }

            template< typename derive_name >
             explicit polymorph( derive_name const& derive_param )
              :base_type( NULL )
              {
               this->F_reset( derive_param );
              }

            //explicit polymorph( type_type      const& P_value );

            ~polymorph() { this->destroy( ); }

            polymorph_type& operator=( polymorph_type const& original_param )
             {
              if( bool(true) == F2_assign( &F1_get(),  original_param.get() ) )
               {
                return *this;
               }
              this->destroy();
              //m_duplicator = original_param.m_duplicator;
              this->F2_assign( &F1_get(), original_param.get() ); //!< druga i zadnja prilika. raport ignorisan;
              return *this;
             }

            /*
            polymorph_type& operator=( type_type const& P_class )
             {
              F2_assign( &F1_get(), &P_class );
              return *this;
             }
            */

            void     destroy( void )
              {
               this->F2_assign( &F1_get(), NULL );
               this->F1_reset( NULL );
              }

            void     reset( type_type *      P_ptr = NULL )
              {
               this->destroy();
               F1_reset( P_ptr );
              }

            bool F_reset( type_type *      P_ptr = NULL )
             {
              this->reset( P_ptr );
              return bool( true );
             }

            template< typename derive_name >
             bool F_reset( derive_name *derive_param )
              {
               this->destroy(); //! ako ovaj vrati false to je internal
               //m_duplicator.TEMPLATE operator()<derive_name>( NULL, reinterpret_cast< derive_name *>( NULL ) ); //! reconfiguration request
               F1_reset( derive_param );
               return bool( true );
             }

            template< typename derive_name >
             bool F_reset( derive_name const& derive_param )
              {
               if( bool( true ) == F2_assign( &F1_get(), &derive_param ) )
                {
                 return bool( true );
                }
               this->destroy();
               //m_duplicator.TEMPLATE operator()<derive_name>( NULL, reinterpret_cast< derive_name *>( NULL ) ); //! reconfiguration request
               return F2_assign( &F1_get(), &derive_param ); //! druga i zadnja prilika. raport ignorisan;
              }

          /*public:
            duplicator_type const& duplicator( void )const
             {
              return m_duplicator;
             }

            void                  duplicator( duplicator_type const& P_duplicator )
             {
              // ? this->destroy(); ? 
              F1_duplicator() = P_duplicator;
             }
          protected:
            duplicator_type      & F1_duplicator(){ return m_duplicator; }
          private:
            duplicator_type m_duplicator;
           */

          private:
            bool F2_assign( type_type** P_ptr, type_type const* P_class )
             {
              return true;
              //return F1_duplicator().Fv_process( P_ptr, P_class );  //! zbog MS-a
              //! return F1_duplicator()( P_ptr, P_class );
             }
         };

   }
 }

#endif



