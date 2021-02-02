# Beating the _std_ lib at parsing

I recently read an article on Hacker News about a fast float to string parser where in they compared the result to the
speed of the standard C++ library. I wondered if I could do the same with a simpler parsing task.

# Cases

## vs to_string

currently getting owned by std.

## vs stoi

not too bad, still a little behind, but not that much.


### Usage

>g++ main.cpp -std=c++17

then run
