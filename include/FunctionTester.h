#ifndef FUNCTIONTESTER_H_
#define FUNCTIONTESTER_H_

#include "ParameterGenerator.h"

namespace speed_test
{

class FunctionTester
{
 public:
   void testMyStringToInt();
   void testMyIntToString();

   void testStdStringToInt();
   void testStdIntToString();
 private:
   ParameterGenerator gen;
};

} // speed_test

#endif