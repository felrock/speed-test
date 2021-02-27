#include <random>
#include <memory>
#include <numeric>

#include "my_functions.h"

const int test_size = 1000000;
const int test_interval = 100;

using timer_func = long long(*)(int);

std::pair<double, double> calc_mean_stddev(std::function<long long(int)> func)
{
    std::vector<double> times;
    for(int i=0; i < test_interval; ++i)
    {
        times.push_back(static_cast<double>(func(test_size)/static_cast<double>(test_size)));
    }

    double mean = std::accumulate(times.begin(), times.end(), 0) / static_cast<double>(test_interval);
    double var  = 0;
    for (const auto& t : times)
    {
        var += (t-mean)*(t-mean);
    }
    double stddev = std::sqrt(var / static_cast<double>(test_size));

    return std::pair<double, double>(mean, stddev);
}

int main(void)
{
    std::cout << "\n[*] Running each function " << test_size << " times \"back-2-back\" and calulucate mean and std deviation...\n" << std::endl;

    std::pair<double, double> result_my_to_string = calc_mean_stddev(static_cast<timer_func>(run_my_to_string));
    std::cout << "[my_to_string] mean-time: " << result_my_to_string.first;
    std::cout << " ns, std-dev: " << result_my_to_string.second << " ns" << std::endl;

    std::pair<double, double> result_to_string = calc_mean_stddev(static_cast<timer_func>(run_to_string));
    std::cout << "[std::to_string] mean-time: " << result_to_string.first;
    std::cout << " ns, std-dev: " << result_to_string.second << " ns" << std::endl;

    std::pair<double, double> result_my_stoi = calc_mean_stddev(static_cast<timer_func>(run_my_stoi));
    std::cout << "[my_stoi] mean-time: " << result_my_stoi.first;
    std::cout << " ns, std-dev: " << result_my_stoi.second << " ns" << std::endl;

    std::pair<double, double> result_stoi = calc_mean_stddev(static_cast<timer_func>(run_stoi));
    std::cout << "[std::stoi] mean-time: " << result_stoi.first;
    std::cout << " ns, std-dev: " << result_stoi.second << " ns" << std::endl;

    return 0;
}
