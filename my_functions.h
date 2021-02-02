#ifndef MY_FUNCTIONS_H_
#define MY_FUNCTIONS_H_

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using Clock = std::chrono::high_resolution_clock;

/* ****************************************************************************************************************** */
/* ***************************************************HELPER CLASSES************************************************* */
/* ****************************************************************************************************************** */

template <class input, class output>
class TestFunction
{
public: 
    TestFunction(const std::string& name,
                 std::function<output(input)> func,
                 const std::vector<std::pair<input, output>>& test_data)
        : _name(name) 
        , _func(func)
        , _test_data(test_data)
    {
    }
    void run(std::ostream& os) 
    {
        int correct_guesses = 0;
        auto t1 = Clock::now();
        for(const auto& [inp, oup] : _test_data)
        {
            if(_func(inp) == oup)
            {
                correct_guesses++;
            }
            else
            {
                std::cout << _func(inp) << " " << oup << std::endl; 
            }
            
        }
        auto t2 = Clock::now();

        os << "[" << correct_guesses << "/" << _test_data.size() << "] " << _name << ": ";
        os << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " ms" << std::endl;
    }
private:
    std::string _name;
    std::function<output(input)> _func;
    const std::vector<std::pair<input, output>>& _test_data;
};

/* ****************************************************************************************************************** */
/* ************************************************FUNCTIONS TO TEST************************************************* */
/* ****************************************************************************************************************** */

// convert from integer to string
std::string my_to_string(const int& number)
{
    if(!number)
    {
        return "0";
    }
    std::string result;
    bool is_neg = false;
    int t_number;
    if(number < 0)
    {
        is_neg = true;
        t_number = -number;
    }
    else
    {
        t_number = number;
    }
    
    while(t_number)
    {
        result = static_cast<char>('0' + t_number % 10) + result;
        t_number /= 10;
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
        number += (str[i] - '0')*pow(10, str.size()-i-1);
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

int pow(const int& a, const int& b)
{
    if(b == 0)
        return 1;
    return a*pow(a, b-1);
}

#endif
