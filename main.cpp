#include <random>
#include <memory>
#include <numeric>

#include "my_functions.h"

const int test_size = 100000;

std::pair<double, double> calc_mean_stddev(std::function<long long(void)> func)
{
    std::vector<double> times;

    for(int i=0; i < test_size; ++i)
    {
        long long time = func();
        times.push_back(static_cast<double>(time));
    }

    double mean = std::accumulate(times.begin(), times.end(), 0) / static_cast<double>(test_size);
    double var  = 0;
    for (const auto& t : times)
    {
        var += (t - mean)*(t-mean);
    }
    double stddev = var / static_cast<double>(test_size);

    return std::pair<double, double>(mean, stddev);
}

int main(void)
{
    std::pair<double, double> result = calc_mean_stddev(static_cast<long long(*)(void)>(run_my_to_string));
    result = calc_mean_stddev(static_cast<long long(*)(void)>(run_to_string));
    result = calc_mean_stddev(static_cast<long long(*)(void)>(run_my_stoi));
    result = calc_mean_stddev(static_cast<long long(*)(void)>(run_stoi));

        std::cout << "[1] my_to_string time: " << t <<  " ms" << std::endl;
        std::cout << "[1] std::to_string time: " << t <<  " ms" << std::endl;
        std::cout << "[1] my_stoi time: " << t <<  " ms" << std::endl;
        std::cout << "[1] std::stoi time: " << t <<  " ms" << std::endl;
    return 0;
}