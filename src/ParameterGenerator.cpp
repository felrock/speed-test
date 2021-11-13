#include "ParameterGenerator.h"

namespace speed_test
{

ParameterGenerator::ParameterGenerator()
{
   rde = std::make_unique<std::default_random_engine>(rd);
   unif_int = std::make_unique<std::uniform_int_distribution<int>>(-10000, 10000);
   unif_double = std::make_unique<std::uniform_real_distribution<double>>(-10000.0, 10000.0);
   unif_float = std::make_unique<std::uniform_real_distribution<float>>(-10000.0, 10000.0);
}

template <typename T>
T ParameterGenerator::genSample()
{
   if (std::is_same<T, StrInt>::value)
   {
      auto unif_ref = *unif_int;
      int random_int = unif_ref(rde);
      return StrInt(std::to_string(random_int), random_int);
   }
   else if (std::is_same<T, StrDouble>::value)
   {
      auto unif_ref = *unif_double;
      double random_double = unif_ref(rde);
      return StrDouble(std::to_string(random_double), random_double);
   }
   else
   {
      auto unif_ref = *unif_float;
      float random_float = unif_ref(rde);
      return StrFloat(std::to_string(random_float), random_float);
   }
}

template<typename T>
std::vector<T> ParameterGenerator::genMulitple(const size_t count)
{
   auto vector = std::vector<T>(count);
   for (size_t i=0; i < count; ++i)
   {
      vector.push_back(genSample<T>());
   }
   return vector;
}

} // speed_test
