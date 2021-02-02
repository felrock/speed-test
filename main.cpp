#include <random>
#include <memory>

#include "my_functions.h"

using namespace std::placeholders;

typedef std::string(*str_to_int_type)(int);
typedef int        (*stoi_type)(const std::string&,std::size_t*,int);


int main(void)
{
    const int test_size = 100000;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(-10000,10000);

    std::vector<std::pair<int, std::string>> numbers_r1;
    std::vector<std::pair<std::string, int>> numbers_r2;
    for(int i=0; i < test_size; ++i)
    {
        int random_number = dist(rng);
        numbers_r1.push_back(std::make_pair(random_number, std::to_string(random_number)));        
        numbers_r2.push_back(std::make_pair(std::to_string(random_number), random_number));        
    }

    TestFunction<int, std::string> test1("my_to_string", my_to_string, numbers_r1);
    test1.run(std::cout);

    TestFunction<int, std::string> test2("std::to_string", static_cast<str_to_int_type>(std::to_string), numbers_r1);
    test2.run(std::cout);

    TestFunction<std::string, int> test3("my_stoi", my_stoi, numbers_r2);
    test3.run(std::cout);

    // take into account that it's a double call, and is faster as single call.
    TestFunction<std::string, int> test4("std::stoi", [](std::string str){return std::stoi(str);}, numbers_r2);
    test4.run(std::cout);

    return 0;
}