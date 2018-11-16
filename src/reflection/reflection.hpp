#ifndef reflection_reflection_26094e85_1b8e_4dab_8e0e_93332c486284
#define reflection_reflection_26094e85_1b8e_4dab_8e0e_93332c486284

#include <string>
#include <array>
#include <map>
#include <set>
#include <vector>
#include <typeinfo>
#include <memory>
#include <algorithm>
#include <functional>
#include <type_traits>

#if defined REFLECTION_USE_PP2FILE
#include "./reflection.pp2f.hpp"
#else
#include "./reflection.body.hpp"
#endif


namespace reflection
 {
  using ::reflection::property::function::execute;
  using ::reflection::content::function::execute;
 }

#endif
