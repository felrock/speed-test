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

inline int nDigits(const int& i)
{
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

inline int findDot(const std::string& str)
{
    int i=0;
    for(const auto& chr : str)
    {
        if(chr == '.' || chr == ',')
            return i;
        i++;
    }
    return -1;
}

// convert from integer to string
inline std::string my_to_string(int number)
{
    if (number == INT_MIN)
    {
        return "-2147483648";
    }
    if (number < 0)
    {
        number = -number; 
        int size = nDigits(number);
        std::string str(size, ' ');
        size--;
        while(number)
        {
            str[size--] = static_cast<char>((number % 10) + 48);
            number /= 10;
        }
        return  "-" + str;
    }
    else
    {
        int size = nDigits(number);
        std::string str(size, ' ');
        size--;
        while(number)
        {
            str[size--] = static_cast<char>((number % 10) + 48);
            number /= 10;
        }
        return str;
    }
}

// convert from string to integer
inline int my_stoi(const std::string& str)
{
    int number = 0;
    int exp = 1;
    int start = str[0] == '-' ? 1 : 0;

    for(int i=str.size()-1; i >= start; --i)
    {
        number += (str[i] - '0')*exp;
        exp    *= 10;
    }
    return start ? -number : number;
}

// convert from string to double
const std::array<double, 10> nums_lrg = {1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0, 10000000.0, 100000000.0, 100000000.0};
const std::array<double, 10> nums_sml = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001, 0.000000001, 0.000000001};

inline double my_stod(const std::string& str)
{
    bool is_neg = false;
    int str_i   = 0;
    if (str[0] == '-')
    {
        is_neg = true;
        str_i  = 1;
    }

    double number = 0.0;
    int dot_i = findDot(str);
    int first_part_size = dot_i;
    int second_part_size = str.size() - dot_i;

    for (int i=first_part_size; i >= 0; --i)
    {
        number += (static_cast<double>(str[str_i++] - '0')*nums_lrg[i]);
    }
    for (int i=second_part_size; i < str.size(); ++i)
    {
        number += (static_cast<double>(str[str_i++] - '0')*nums_sml[i]);
    }

    if (is_neg)
        return -number;
    return number;
}

inline std::string to_string(double number)
{
    int lrg_part_int = static_cast<int>(number);
    std::string lrg_part_str = my_to_string(lrg_part_int);
    lrg_part_str += '.';
    double sml_part_doub = (number - static_cast<double>(lrg_part_int))*10.0;
    while(sml_part_doub)
    {
        lrg_part_str += static_cast<char>(static_cast<int>(sml_part_doub)%10 + 48);
        sml_part_doub *= 10.0;
    }
    return lrg_part_str;    
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
