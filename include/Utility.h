#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>

namespace speed_test
{

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
        {
            return i;
        }
        i++;
    }
    return -1;
}

inline void doRandomWork()
{
}

} // speed_test

#endif