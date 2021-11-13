#include <random>
#include <memory>
#include <numeric>
#include <fstream>

#include "FunctionTester.h"

const int test_size = 1000000;
const int test_interval = 100;

std::pair<double, double> calc_mean_std(std::vector<double> times)
{
    double mean = std::accumulate(times.begin(), times.end(), 0) / static_cast<double>(test_interval);
    double var  = 0;
    for (const auto& t : times)
    {
        var += (t-mean)*(t-mean);
    }
    double std = std::sqrt(var / static_cast<double>(test_interval));

    return std::pair<double, double>(mean, std);
}

int main(void)
{
    std::vector<std::tuple<std::string, double, double>> results;
    speed_test::FunctionTester ft;
    std::vector<double> times;
    std::cout << "\n[*] Running each function " << test_size << " times \"back-2-back\" and calulucate mean and std deviation...\n" << std::endl;

    for (size_t i=0; i < test_interval; ++i)
    {
        ft.testMyIntToString(test_size);
        times.push_back(ft.getTime());
    }
    std::pair<double, double> result_my_to_string = calc_mean_std(times);
    std::cout << "[my_to_string] mean-time: " << result_my_to_string.first;
    std::cout << " ns, std-dev: " << result_my_to_string.second << " ns" << std::endl;
    results.push_back({"my_to_string", result_my_to_string.first, result_my_to_string.second});

    for (size_t i=0; i < test_interval; ++i)
    {
        ft.testStdIntToString(test_size);
        times.push_back(ft.getTime());
    }
    std::pair<double, double> result_to_string = calc_mean_std(times);
    std::cout << "[std::to_string] mean-time: " << result_to_string.first;
    std::cout << " ns, std-dev: " << result_to_string.second << " ns" << std::endl;
    results.push_back({"std::to_string", result_to_string.first, result_to_string.second});

    for (size_t i=0; i < test_interval; ++i)
    {
        ft.testMyStringToInt(test_size);
        times.push_back(ft.getTime());
    }
    std::pair<double, double> result_my_stoi = calc_mean_std(times);
    std::cout << "[my_stoi] mean-time: " << result_my_stoi.first;
    std::cout << " ns, std-dev: " << result_my_stoi.second << " ns" << std::endl;
    results.push_back({"my_stoi", result_my_stoi.first, result_my_stoi.second});

    for (size_t i=0; i < test_interval; ++i)
    {
        ft.testStdStringToInt(test_size);
        times.push_back(ft.getTime());
    }
    std::pair<double, double> result_stoi = calc_mean_std(times);
    std::cout << "[std::stoi] mean-time: " << result_stoi.first;
    std::cout << " ns, std-dev: " << result_stoi.second << " ns" << std::endl;
    results.push_back({"std::stoi", result_stoi.first, result_stoi.second});

    // write to file
    std::ofstream file_str_to_int("string_to_int.csv");
    for(const auto& res : results)
    {
        file_str_to_int << std::get<0>(res) << ", " << std::get<1>(res) << ", " << std::get<2>(res) << std::endl;
    }
    file_str_to_int.close();

    return 0;
}
