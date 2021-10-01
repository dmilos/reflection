#ifndef reflection_define_idspec
#define reflection_define_idspec

// reflection__IDSPEC( identificator_symbolic_name, class_string_name, class_symbolic_name )





#define reflection__IDSPEC( identificator_symbolic_name, class_string_name, class_symbolic_name )     \
namespace reflection                                                                                  \
 {                                                                                                    \
  namespace type                                                                                      \
   {                                                                                                  \
    namespace name                                                                                    \
     {                                                                                                \
                                                                                                      \
      template <>                                                                                     \
       inline typename identificatorX<identificator_symbolic_name>::identifier_type const&            \
       identificatorX<identificator_symbolic_name>::template get< class_symbolic_name >()             \
        {                                                                                             \
         static identificatorX<identificator_symbolic_name>::identifier_type id( class_string_name ); \
         return id;                                                                                   \
        }                                                                                             \
                                                                                                      \
    }                                                                                                 \
   }                                                                                                  \
 }

// reflection__IDSPEC( std::string, "std::int8_t",        std::int8_t )
// reflection__IDSPEC( std::string, "std::int16_t",       std::int16_t )
// reflection__IDSPEC( std::string, "std::int32_t",       std::int32_t )
// reflection__IDSPEC( std::string, "std::int64_t",       std::int64_t )
//
// reflection__IDSPEC( std::string, "std::uint8_t",        std::uint8_t )
// reflection__IDSPEC( std::string, "std::uint16_t",       std::uint16_t )
// reflection__IDSPEC( std::string, "std::uint32_t",       std::uint32_t )
// reflection__IDSPEC( std::string, "std::uint64_t",       std::uint64_t )


reflection__IDSPEC( std::string, "std::string",            std::string )
reflection__IDSPEC( std::string, "std::string const",      std::string const )
reflection__IDSPEC( std::string, "std::string const &",    std::string const & )

reflection__IDSPEC( std::string, "std::wstring",            std::wstring )
reflection__IDSPEC( std::string, "std::wstring const",      std::wstring const )
reflection__IDSPEC( std::string, "std::wstring const &",    std::wstring const & )

reflection__IDSPEC( std::string, "std::vector<std::uint8_t>",   std::vector<std::uint8_t>  )
reflection__IDSPEC( std::string, "std::vector<std::uint16_t>",  std::vector<std::uint16_t> )
reflection__IDSPEC( std::string, "std::vector<std::uint32_t>",  std::vector<std::uint32_t> )
reflection__IDSPEC( std::string, "std::vector<std::uint64_t>",  std::vector<std::uint64_t> )

reflection__IDSPEC( std::string, "std::vector<std::int8_t>",        std::vector<std::int8_t> )
reflection__IDSPEC( std::string, "std::vector<std::int16_t>",       std::vector<std::int16_t> )
reflection__IDSPEC( std::string, "std::vector<std::int32_t>",       std::vector<std::int32_t> )
reflection__IDSPEC( std::string, "std::vector<std::int64_t>",       std::vector<std::int64_t> )

reflection__IDSPEC( std::string, "std::vector<float>",          std::vector<float> )
reflection__IDSPEC( std::string, "std::vector<double>",         std::vector<double> )
reflection__IDSPEC( std::string, "std::vector<long double>",    std::vector<long double> )

reflection__IDSPEC( std::string, "std::vector<std::string>",    std::vector<std::string> )
reflection__IDSPEC( std::string, "std::vector<std::wstring>",   std::vector<std::wstring> )

reflection__IDSPEC( std::string, "std::list<std::uint8_t>",     std::list<std::uint8_t>  )
reflection__IDSPEC( std::string, "std::list<std::uint16_t>",    std::list<std::uint16_t> )
reflection__IDSPEC( std::string, "std::list<std::uint32_t>",    std::list<std::uint32_t> )
reflection__IDSPEC( std::string, "std::list<std::uint64_t>",    std::list<std::uint64_t> )

reflection__IDSPEC( std::string, "std::list<std::int8_t>",     std::list<std::int8_t>  )
reflection__IDSPEC( std::string, "std::list<std::int16_t>",    std::list<std::int16_t> )
reflection__IDSPEC( std::string, "std::list<std::int32_t>",    std::list<std::int32_t> )
reflection__IDSPEC( std::string, "std::list<std::int64_t>",    std::list<std::int64_t> )

reflection__IDSPEC( std::string, "std::list<float>",         std::list<float> )
reflection__IDSPEC( std::string, "std::list<double>",        std::list<double> )
reflection__IDSPEC( std::string, "std::list<long double>",   std::list<long double> )
reflection__IDSPEC( std::string, "std::list<std::string>",   std::list<std::string> )
reflection__IDSPEC( std::string, "std::list<std::wstring>",  std::list<std::wstring> )

reflection__IDSPEC( std::string, "std::set<std::uint8_t>",     std::set<std::uint8_t>  )
reflection__IDSPEC( std::string, "std::set<std::uint16_t>",    std::set<std::uint16_t> )
reflection__IDSPEC( std::string, "std::set<std::uint32_t>",    std::set<std::uint32_t> )
reflection__IDSPEC( std::string, "std::set<std::uint64_t>",    std::set<std::uint64_t> )

reflection__IDSPEC( std::string, "std::set<std::int8_t>",     std::set<std::int8_t>  )
reflection__IDSPEC( std::string, "std::set<std::int16_t>",    std::set<std::int16_t> )
reflection__IDSPEC( std::string, "std::set<std::int32_t>",    std::set<std::int32_t> )
reflection__IDSPEC( std::string, "std::set<std::int64_t>",    std::set<std::int64_t> )

reflection__IDSPEC( std::string, "std::set<float>",         std::set<float> )
reflection__IDSPEC( std::string, "std::set<double>",        std::set<double> )
reflection__IDSPEC( std::string, "std::set<long double>",   std::set<long double> )
reflection__IDSPEC( std::string, "std::set<std::string>",   std::set<std::string> )
reflection__IDSPEC( std::string, "std::set<std::wstring>",  std::set<std::wstring> )

reflection__IDSPEC( std::string, "std::complex<float>",        std::complex<float> )
reflection__IDSPEC( std::string, "std::complex<double>",       std::complex<double> )
reflection__IDSPEC( std::string, "std::complex<long double>",  std::complex<long double> )

#ifdef COMMA
#error "COMA macro should not be defined"
#endif

#define COMMA ,

reflection__IDSPEC( std::string, "std::map<int,int>",            std::map<int COMMA int          > )
reflection__IDSPEC( std::string, "std::map<int,unsigned>",       std::map<int COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::map<int,float>",          std::map<int COMMA float        > )
reflection__IDSPEC( std::string, "std::map<int,double>",         std::map<int COMMA double       > )
reflection__IDSPEC( std::string, "std::map<int,std::string>",    std::map<int COMMA std::string  > )
reflection__IDSPEC( std::string, "std::map<int,std::wstring>",   std::map<int COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::map<unsigned,int>",            std::map<unsigned COMMA int          > )
reflection__IDSPEC( std::string, "std::map<unsigned,unsigned>",       std::map<unsigned COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::map<unsigned,float>",          std::map<unsigned COMMA float        > )
reflection__IDSPEC( std::string, "std::map<unsigned,double>",         std::map<unsigned COMMA double       > )
reflection__IDSPEC( std::string, "std::map<unsigned,std::string>",    std::map<unsigned COMMA std::string  > )
reflection__IDSPEC( std::string, "std::map<unsigned,std::wstring>",   std::map<unsigned COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::map<float,int>",            std::map<float COMMA int          > )
reflection__IDSPEC( std::string, "std::map<float,unsigned>",       std::map<float COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::map<float,float>",          std::map<float COMMA float        > )
reflection__IDSPEC( std::string, "std::map<float,double>",         std::map<float COMMA double       > )
reflection__IDSPEC( std::string, "std::map<float,std::string>",    std::map<float COMMA std::string  > )
reflection__IDSPEC( std::string, "std::map<float,std::wstring>",   std::map<float COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::map<double,int>",            std::map<double COMMA int          > )
reflection__IDSPEC( std::string, "std::map<double,unsigned>",       std::map<double COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::map<double,float>",          std::map<double COMMA float        > )
reflection__IDSPEC( std::string, "std::map<double,double>",         std::map<double COMMA double       > )
reflection__IDSPEC( std::string, "std::map<double,std::string>",    std::map<double COMMA std::string  > )
reflection__IDSPEC( std::string, "std::map<double,std::wstring>",   std::map<double COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::map<std::string,int>",            std::map<std::string COMMA int          > )
reflection__IDSPEC( std::string, "std::map<std::string,unsigned>",       std::map<std::string COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::map<std::string,float>",          std::map<std::string COMMA float        > )
reflection__IDSPEC( std::string, "std::map<std::string,double>",         std::map<std::string COMMA double       > )
reflection__IDSPEC( std::string, "std::map<std::string,std::string>",    std::map<std::string COMMA std::string  > )
reflection__IDSPEC( std::string, "std::map<std::string,std::wstring>",   std::map<std::string COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::map<std::wstring,int>",            std::map<std::wstring COMMA int          > )
reflection__IDSPEC( std::string, "std::map<std::wstring,unsigned>",       std::map<std::wstring COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::map<std::wstring,float>",          std::map<std::wstring COMMA float        > )
reflection__IDSPEC( std::string, "std::map<std::wstring,double>",         std::map<std::wstring COMMA double       > )
reflection__IDSPEC( std::string, "std::map<std::wstring,std::string>",    std::map<std::wstring COMMA std::string  > )
reflection__IDSPEC( std::string, "std::map<std::wstring,std::wstring>",   std::map<std::wstring COMMA std::wstring > )


reflection__IDSPEC( std::string, "std::pair<const int, int>",                std::pair< const int COMMA int          > )
reflection__IDSPEC( std::string, "std::pair<const int, unsigned>",           std::pair< const int COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::pair<const int, float>",              std::pair< const int COMMA float        > )
reflection__IDSPEC( std::string, "std::pair<const int, double>",             std::pair< const int COMMA double       > )
reflection__IDSPEC( std::string, "std::pair<const int, std::string>",        std::pair< const int COMMA std::string  > )
reflection__IDSPEC( std::string, "std::pair<const int, std::wstring>",       std::pair< const int COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::pair<const unsigned, int>",                std::pair< const unsigned COMMA int          > )
reflection__IDSPEC( std::string, "std::pair<const unsigned, unsigned>",           std::pair< const unsigned COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::pair<const unsigned, float>",              std::pair< const unsigned COMMA float        > )
reflection__IDSPEC( std::string, "std::pair<const unsigned, double>",             std::pair< const unsigned COMMA double       > )
reflection__IDSPEC( std::string, "std::pair<const unsigned, std::string>",        std::pair< const unsigned COMMA std::string  > )
reflection__IDSPEC( std::string, "std::pair<const unsigned, std::wstring>",       std::pair< const unsigned COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::pair<const std::string, int>",                std::pair< const std::string COMMA int          > )
reflection__IDSPEC( std::string, "std::pair<const std::string, unsigned>",           std::pair< const std::string COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::pair<const std::string, float>",              std::pair< const std::string COMMA float        > )
reflection__IDSPEC( std::string, "std::pair<const std::string, double>",             std::pair< const std::string COMMA double       > )
reflection__IDSPEC( std::string, "std::pair<const std::string, std::string>",        std::pair< const std::string COMMA std::string  > )
reflection__IDSPEC( std::string, "std::pair<const std::string, std::wstring>",       std::pair< const std::string COMMA std::wstring > )

reflection__IDSPEC( std::string, "std::pair<const std::wstring, int>",                std::pair< const std::wstring COMMA int          > )
reflection__IDSPEC( std::string, "std::pair<const std::wstring, unsigned>",           std::pair< const std::wstring COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::pair<const std::wstring, float>",              std::pair< const std::wstring COMMA float        > )
reflection__IDSPEC( std::string, "std::pair<const std::wstring, double>",             std::pair< const std::wstring COMMA double       > )
reflection__IDSPEC( std::string, "std::pair<const std::wstring, std::string>",        std::pair< const std::wstring COMMA std::string  > )
reflection__IDSPEC( std::string, "std::pair<const std::wstring, std::wstring>",       std::pair< const std::wstring COMMA std::wstring > )


#undef COMMA

#endif
