#ifndef reflection_operation_transfer_equalizer
#define reflection_operation_transfer_equalizer

// ::reflection::operation::transfer::equalizer_class<identifier_name,report_name>

#include "../property/assign.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

        template
         <
           typename  identifier_name = std::string
          ,typename      report_name = bool
         >
         struct equalizer_class
          {
           public:
             typedef  identifier_name    identifier_type;
             typedef      report_name        report_type;

             typedef ::reflection::property::pure_class                                 property_type;
             typedef ::reflection::ornament::category_class<identifier_type>            category_type;


             typedef  std::function < report_name ( property_type &, property_type const& ) > action_type;

             typedef std::pair< identifier_type, identifier_type > relation_type;

             typedef std::map< relation_type, action_type > container_type;

           public:
             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           public:
             equalizer_class( )
              {
               this->template register_default< bool,     bool       >( );

               this->template register_default< char          >( );
               this->template register_default< unsigned char >( );
               this->template register_default< wchar_t       >( );
               this->template register_default< std::wint_t   >( );
               this->template register_default< char16_t      >( );
               this->template register_default< char32_t      >( );

               this->template register_default< std::int8_t   >( );
               this->template register_default< std::int16_t  >( );
               this->template register_default< std::int32_t  >( );
               this->template register_default< std::int64_t  >( );
               this->template register_default< std::uint8_t  >( );
               this->template register_default< std::uint16_t >( );
               this->template register_default< std::uint32_t >( );
               this->template register_default< std::uint64_t >( );

               this->template register_default<       float   >( );
               this->template register_default<      double   >( );
               this->template register_default<  long double  >( );

               this->template register_default< void*         >( );

               this->template register_default< short                >( );
               this->template register_default< unsigned short       >( );
               this->template register_default< int                  >( );
               this->template register_default< unsigned int         >( );
               this->template register_default< long                 >( );
               this->template register_default< long long            >( );
               this->template register_default< unsigned long        >( );
               this->template register_default< unsigned long long   >( );

               this->template register_default< std::string   >( );
               this->template register_default< std::wstring  >( );
               this->template register_default< std::u16string>( );
               this->template register_default< std::u32string>( );

               this->template register_default< std::complex< float       > >( );
               this->template register_default< std::complex< double      > >( );
               this->template register_default< std::complex< long double > >( );

               // TODO this->template register_vector< double >( );
             }

           public:
             template< typename left_name, typename right_name = left_name >
              void register_default()
               {
                relation_type relation( identificator_type::template get< left_name >(), identificator_type::template get< right_name >() );
                auto action = &::reflection::property::convert< left_name const&, left_name&, right_name const&,  report_name >;
                m_container.emplace( relation, action );
               }

           public:
             report_name align( property_type & left, property_type const& right )const
              {
               relation_type relation;

               relation.first = identificator_type::NAT();
               category_type *category_left = dynamic_cast<  category_type*  >( &left );
               if( nullptr != category_left )
                {
                 relation.first = category_left->identifier();
                }

               relation.second = identificator_type::NAT();
               category_type const*  category_right = dynamic_cast< const category_type*  >( &right );
               if( nullptr != category_right )
                {
                 relation.second = category_right->identifier();
                }

               switch(   ( ( identificator_type::NAT() != relation.first  ) ? 1 :0 )
                        +( ( identificator_type::NAT() != relation.second ) ? 2 :0 )
                     )
                {
                 case( 0 ): return report_name( false ); break;
                 case( 1 ): relation.second =  relation.first; break;
                 case( 2 ): relation.first  = relation.second; break;
                }

               auto iterator = m_container.find( relation );
               if( iterator == m_container.end() )
                {
                 return report_name( false );
                }

               return iterator->second( left, right );
              }

           private:
             container_type m_container;
          };

     }
   }
 }

#endif
