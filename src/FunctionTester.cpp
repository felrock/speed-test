#include "FunctionTester.h"

namespace speed_test
{

void FunctionTester::testStdIntToString(const int iteration_count)
{
    auto input = gen.genMulitple<StrInt>(iteration_count);

    int right_ans = 0;
    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        if (std::to_string(inp.second) == inp.first)
        {
            continue;
        }
    }
    auto t2 = Clock::now();

    test_time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
}

void FunctionTester::testMyIntToString(const int iteration_count)
{
    auto input = gen.genMulitple<StrInt>(iteration_count);

    int right_ans = 0;
    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        if (my_to_string(inp.second) == inp.first)
        {
            continue;
        }
    }
    auto t2 = Clock::now();

    test_time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
}
void FunctionTester::testStdStringToInt(const int iteration_count)
{
    auto input = gen.genMulitple<StrInt>(iteration_count);

    int right_ans = 0;
    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        if (std::stoi(inp.first) == inp.second)
        {
            continue;
        }
    }
    auto t2 = Clock::now();

    test_time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
}

void FunctionTester::testMyStringToInt(const int iteration_count)
{
    auto input = gen.genMulitple<StrInt>(iteration_count);

    int right_ans = 0;
    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        if (my_stoi(inp.first) == inp.second)
        {
            continue;
        }
    }
    auto t2 = Clock::now();

    test_time = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
}

void FunctionTester::doRandomWork()
{
    // implement some random work switch case...
}

double FunctionTester::getTime()
{
    return static_cast<double>(test_time.count());
}

} // speed_test