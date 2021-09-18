#ifndef IPARAMETER_GENERATOR_H_
#define IPARAMETER_GENERATOR_H_

#include <memory>
#include <random>
#include <string>

namespace speed_test
{

class ParameterGenerator
{
 public:
   ParameterGenerator();

   std::pair<std::string, int> genStrInt();
   std::pair<int, std::string> genIntStr();

   std::pair<double, std::string> genDoubleStr();
   std::pair<std::string, double> genStrDouble();

   std::pair<float, std::string> genFloatStr();
   std::pair<std::string, float> genStrFloat();
 private:
   std::random_device rd;
   std::unique_ptr<std::default_random_engine> rde;
   std::unique_ptr<std::uniform_int_distribution<int>> unif_int;
   std::unique_ptr<std::uniform_real_distribution<double>> unif_double;
   std::unique_ptr<std::uniform_real_distribution<float>> unif_float;
};


} // speed_test

#endif