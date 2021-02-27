#ifndef MY_FUNCTIONS_H_
#define MY_FUNCTIONS_H_

#include <array>
#include <assert.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using Clock = std::chrono::high_resolution_clock;

/* ****************************************************************************************************************** */
/* ************************************************FUNCTIONS TO TEST************************************************* */
/* ****************************************************************************************************************** */

inline int nDigits(int i)
{
    if (i < 0) i = -i;
    if (i <         10) return 1;
    if (i <        100) return 2;
    if (i <       1000) return 3;
    if (i <      10000) return 4;
    if (i <     100000) return 5;
    if (i <    1000000) return 6;      
    if (i <   10000000) return 7;
    if (i <  100000000) return 8;
    if (i < 1000000000) return 9;
    return 10;
}

// convert from integer to string
inline std::string my_to_string(int number)
{
    if (number < 0)
    {
        std::string str;
        number = -number; 
        while(number)
        {
            str += ((number % 10) + 48);
            number /= 10;
        }
        return  "-" + str;
    }
    else
    {
        std::string str;
        while(number)
        {
            str += ((number % 10) + 48);
            number /= 10;
        }
        return str;
    }
}

// convert from string to integer
inline int my_stoi(const std::string& str)
{
    int number = 0, exp = 1;
    for(int i=str.size()-1; i >= 1; --i)
    {
        number += (str[i] - '0')*exp;
        exp    *= 10;
    }
    return str[0] == '-' ? -number : number;
}

/* ****************************************************************************************************************** */
/* ***************************************************HELPER FUNCTIONS*********************************************** */
/* ****************************************************************************************************************** */

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<int> dist(-10000000, 10000000);

long long run_to_string(int times)
{
    std::vector<int> input;
    for(int i=0; i < times; ++i)
    {
        input.push_back(dist(rng));
    }

    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        std::to_string(inp);
    }
    auto t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}

long long run_my_to_string(int times)
{
    std::vector<int> input;
    for(int i=0; i < times; ++i)
    {
        input.push_back(dist(rng));
    }

    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        my_to_string(inp);
    }
    auto t2 = Clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}

long long run_stoi(int times)
{
    std::vector<std::string> input;
    for(int i=0; i < times; ++i)
    {
        input.push_back(std::to_string(dist(rng)));
    }

    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        std::stoi(inp);
    }
    auto t2 = Clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}

long long run_my_stoi(int times)
{
    std::vector<std::string> input;
    for(int i=0; i < times; ++i)
    {
        input.push_back(std::to_string(dist(rng)));
    }

    auto t1 = Clock::now();
    for(const auto& inp : input)
    {
        my_stoi(inp);
    }
    auto t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}

#endif
