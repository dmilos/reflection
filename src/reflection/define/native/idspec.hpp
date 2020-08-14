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

reflection__IDSPEC( std::string, "std::string",            std::string )
reflection__IDSPEC( std::string, "std::string const",      std::string const )
reflection__IDSPEC( std::string, "std::string const &",    std::string const & )

reflection__IDSPEC( std::string, "std::wstring",            std::wstring )
reflection__IDSPEC( std::string, "std::wstring const",      std::wstring const )
reflection__IDSPEC( std::string, "std::wstring const &",    std::wstring const & )

reflection__IDSPEC( std::string, "std::vector<int>",            std::vector<int> )
reflection__IDSPEC( std::string, "std::vector<unsigned>",       std::vector<unsigned> )
reflection__IDSPEC( std::string, "std::vector<float>",          std::vector<float> )
reflection__IDSPEC( std::string, "std::vector<double>",         std::vector<double> )
reflection__IDSPEC( std::string, "std::vector<std::string>",    std::vector<std::string> )
reflection__IDSPEC( std::string, "std::vector<std::wstring>",   std::vector<std::wstring> )

reflection__IDSPEC( std::string, "std::list<int>",           std::list<int> )
reflection__IDSPEC( std::string, "std::list<unsigned>",      std::list<unsigned> )
reflection__IDSPEC( std::string, "std::list<float>",         std::list<float> )
reflection__IDSPEC( std::string, "std::list<double>",        std::list<double> )
reflection__IDSPEC( std::string, "std::list<std::string>",   std::list<std::string> )
reflection__IDSPEC( std::string, "std::list<std::wstring>",  std::list<std::wstring> )

reflection__IDSPEC( std::string, "std::set<int>",           std::set<int> )
reflection__IDSPEC( std::string, "std::set<unsigned>",      std::set<unsigned> )
reflection__IDSPEC( std::string, "std::set<float>",         std::set<float> )
reflection__IDSPEC( std::string, "std::set<double>",        std::set<double> )
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

reflection__IDSPEC( std::string, "std::pair<int,int>",                std::pair<double COMMA int          > )
reflection__IDSPEC( std::string, "std::pair<int,unsigned>",           std::pair<double COMMA unsigned     > )
reflection__IDSPEC( std::string, "std::pair<int,float>",              std::pair<double COMMA float        > )
reflection__IDSPEC( std::string, "std::pair<int,double>",             std::pair<double COMMA double       > )
reflection__IDSPEC( std::string, "std::pair<int,std::string>",        std::pair<double COMMA std::string  > )
reflection__IDSPEC( std::string, "std::pair<int,std::wstring>",       std::pair<double COMMA std::wstring > )

#undef COMMA

#endif

