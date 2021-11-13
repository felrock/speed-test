#ifndef PARAMETERGENERATOR_H_
#define PARAMETERGENERATOR_H_

#include <memory>
#include <random>
#include <string>

namespace speed_test
{
  using StrInt = std::pair<std::string, int>;
  using StrDouble = std::pair<std::string, double>;
  using StrFloat = std::pair<std::string, float>;

class ParameterGenerator
{
 public:
  ParameterGenerator();

  template <typename T>
  T genSample();
  template <typename T>
  std::vector<T> genMulitple(const size_t count);

 private:
  std::random_device rd;
  std::unique_ptr<std::default_random_engine> rde;
  std::unique_ptr<std::uniform_int_distribution<int>> unif_int;
  std::unique_ptr<std::uniform_real_distribution<double>> unif_double;
  std::unique_ptr<std::uniform_real_distribution<float>> unif_float;
};


} // speed_test

#endif