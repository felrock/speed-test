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

const std::array<std::string, 100> digit_pairs = {
  "00", "01", "02", "03", "04", "05", "06", "07", "08", "09",
  "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
  "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
  "30", "31", "32", "33", "34", "35", "36", "37", "38", "39",
  "40", "41", "42", "43", "44", "45", "46", "47", "48", "49",
  "50", "51", "52", "53", "54", "55", "56", "57", "58", "59",
  "60", "61", "62", "63", "64", "65", "66", "67", "68", "69",
  "70", "71", "72", "73", "74", "75", "76", "77", "78", "79",
  "80", "81", "82", "83", "84", "85", "86", "87", "88", "89",
  "90", "91", "92", "93", "94", "95", "96", "97", "98", "99"
};
const std::array<std::array<int, 10>, 10> base_ten_mult = {{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000},
    {2, 20, 200, 2000, 20000, 200000, 2000000, 20000000, 200000000, 2000000000},
    {3, 30, 300, 3000, 30000, 300000, 3000000, 30000000, 300000000, 0},
    {4, 40, 400, 4000, 40000, 400000, 4000000, 40000000, 400000000, 0},
    {5, 50, 500, 5000, 50000, 500000, 5000000, 50000000, 500000000, 0},
    {6, 60, 600, 6000, 60000, 600000, 6000000, 60000000, 600000000, 0},
    {7, 70, 700, 7000, 70000, 700000, 7000000, 70000000, 700000000, 0},
    {8, 80, 800, 8000, 80000, 800000, 8000000, 80000000, 800000000, 0},
    {9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000, 0},
}};

// convert from integer to string
std::string my_to_string(const int& number)
{
    if(!number)
    {
        return "0";
    }
    
    if(number == INT_MIN)
    {
        return "-2147483647";
    }

    std::string result;
    bool is_neg = false;
    int t_number, size=0;

    if(number < 0)
    {
        is_neg = true;
        t_number = -number;
    }
    else
    {
        t_number = number;
    }

    for(const auto& mlt : base_ten_mult[0])
    {
        if(mlt > t_number)
        {
            break;
        }
        ++size;
    }
    result.resize(size);

    for(int i=size-1; i > 0; i-=2)
    {
        int t_mod_ = t_number % 100;
        result[i] = digit_pairs[t_mod_][1];
        result[i-1] = digit_pairs[t_mod_][0];
        t_number /= 100;
    }

    if(t_number > 0)
    {
        int t_mod_ = t_number % 10;
        result[0] = digit_pairs[t_mod_][1];
    }

    if(is_neg)
    {
        return '-' + result;
    }
    else
    {
        return result;
    }
}

// convert from string to integer
int my_stoi(const std::string& str)
{
    int number = 0;
    const int size = str.size();
    const int size_sub = str.size() - 1;
    if(str[0] == '-')
    {
        for(int i=1; i < size; ++i)
        {
            number += base_ten_mult[str[i]-'0'][size_sub-i];
        }
        return -number;
    }
    else
    {
        for(int i=1; i < size; ++i)
        {
            number += base_ten_mult[str[i]-'0'][size_sub-i];
        }
        return number;
    }
}

/* ****************************************************************************************************************** */
/* ***************************************************HELPER FUNCTIONS*********************************************** */
/* ****************************************************************************************************************** */

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<int> dist(-10000, 10000);

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
        std::stoi(inp);
    }
    auto t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}

#endif
