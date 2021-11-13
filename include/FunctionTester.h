#ifndef FUNCTIONTESTER_H_
#define FUNCTIONTESTER_H_

#include "ParameterGenerator.h"
#include "MyFunctions.h"
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

namespace speed_test
{

class FunctionTester
{
 public:
  void testMyStringToInt(const int iteration_count);
  void testMyIntToString(const int iteration_count);

  void testStdStringToInt(const int iteration_count);
  void testStdIntToString(const int iteration_count);

  void doRandomWork();
  double getTime();
 private:
  ParameterGenerator gen;
  std::chrono::nanoseconds test_time;
};

} // speed_test

#endif