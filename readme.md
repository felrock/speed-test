# Beating the _std_ lib at parsing

I recently read an article on Hacker News about a fast float to string parser where in they compared the result to the
speed of the standard C++ library. So naturally I wondered if I could do the same with simple parsing tasks.

## No magic tricks

I will chose the algorithm I could think of at the time, with a little bit of searching online. Starting with to_string and stoi, since I think those are the simplest to implement. I will gradually work towards the parsing methods that are a lot harder to implement correct with many edge cases(I will problably miss a few edge cases too).

# Cases

## vs to_string
currently getting owned by std.

## vs stoi
not too bad, still a little behind, but not that much.


## Usage

>g++ main.cpp -std=c++17

then run