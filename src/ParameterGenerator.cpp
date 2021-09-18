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

std::pair<int, std::string> ParameterGenerator::genIntStr()
{
   auto unif_ref = *unif_int;
   int random_int = unif_ref(rde);
   return std::pair<int, std::string>(random_int, std::to_string(random_int));
}

std::pair<std::string, int> ParameterGenerator::genStrInt()
{
   auto unif_ref = *unif_int;
   int random_int = unif_ref(rde);
   return std::pair<std::string, int>(std::to_string(random_int), random_int);
}

std::pair<double, std::string> ParameterGenerator::genDoubleStr()
{
   auto unif_ref = *unif_double;
   double random_double = unif_ref(rde);
   return std::pair<double, std::string>(random_double, std::to_string(random_double));
}

std::pair<std::string, double> ParameterGenerator::genStrDouble()
{
   auto unif_ref = *unif_double;
   double random_double = unif_ref(rde);
   return std::pair<std::string, double>(std::to_string(random_double), random_double);
};

std::pair<float, std::string> ParameterGenerator::genFloatStr()
{
   auto unif_ref = *unif_float;
   float random_float = unif_ref(rde);
   return std::pair<float, std::string>(random_float, std::to_string(random_float));
};

std::pair<std::string, float> ParameterGenerator::genStrFloat()
{
   auto unif_ref = *unif_float;
   float random_float = unif_ref(rde);
   return std::pair<std::string, float>(std::to_string(random_float), random_float);
};

} // speed_test
