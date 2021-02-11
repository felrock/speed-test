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
const std::array<int, 10> base_ten_mult = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

// convert from integer to string
std::string my_to_string(const int& number)
{
    if(!number)
    {
        return "0";
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
    for(const auto& mlt : base_ten_mult)
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
    int number(0), stop(0);
    bool is_neg = str[0] == '-' ? true : false;
    if(is_neg)
    {
        stop = 1;
    }
    for(int i=stop; i < str.size(); ++i)
    {
        number += (str[i] - '0')*base_ten_mult[str.size()-i-1];
    }
    if(is_neg)
    {
        return -number;
    }
    else
    {
        return number;
    }
}

/* ****************************************************************************************************************** */
/* ***************************************************HELPER FUNCTIONS*********************************************** */
/* ****************************************************************************************************************** */

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(-10000,10000);


long long run_to_string(const int& input, const std::string& output, bool& correct) 
{
    int correct_guesses = 0;
    auto t1 = Clock::now();
    std::string str = std::to_string(input);
    auto t2 = Clock::now();
    correct = (str == output);

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long long run_to_string() 
{
    int random_number = dist(rng);
    auto t1 = Clock::now();
    std::string str = std::to_string(random_number);
    auto t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long long run_my_to_string(const int& input, const std::string& output, bool& correct) 
{
    int correct_guesses = 0;
    auto t1 = Clock::now();
    std::string str = my_to_string(input);
    auto t2 = Clock::now();
    correct = (str == output);

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long long run_my_to_string() 
{
    int random_number = dist(rng);
    auto t1 = Clock::now();
    std::string str = my_to_string(random_number);
    auto t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long long run_my_stoi(const std::string& input, const int& output, bool& correct) 
{
    int correct_guesses = 0;
    auto t1 = Clock::now();
    int i = my_stoi(input);
    auto t2 = Clock::now();
    correct = (i == output);

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long long run_my_stoi() 
{
    std::string random_number = std::to_string(dist(rng));
    auto t1 = Clock::now();
    int i = my_stoi(random_number);
    auto t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long long run_stoi(const std::string& input, const int& output, bool& correct) 
{
    int correct_guesses = 0;
    auto t1 = Clock::now();
    int i = std::stoi(input);
    auto t2 = Clock::now();
    correct = (i == output);

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

long long run_stoi() 
{
    std::string random_number = std::to_string(dist(rng));
    auto t1 = Clock::now();
    int i = std::stoi(random_number);
    auto t2 = Clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
}

#endif
