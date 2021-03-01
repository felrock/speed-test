# std vs my_func 

This is a repo for testing the difference in speed between a simple my_func and the C++ standard library(C++17). These test are in no way complete or conclusive, it's just for fun. *my_func* implementations are really simple, with emphasis on readability. The result could be different on your machine. I plan on adding more function comparisons in the future.

# :rocket: Cases

## :clock1: Converting std::string to int and back

<p align=center>

<img src="https://raw.githubusercontent.com/felrock/my_func-speed-test/main/images/to_string.jpg" />
</p>

### my_to_string vs std::to_string

Example run:

```
[my_to_string] mean-time: 88.74 ns, std-dev: 14.4389 ns
[std::to_string] mean-time: 54.11 ns, std-dev: 6.41044 ns
```

std::string is faster for sure in this test. 


### my_stoi vs std::stoi

Example run:

```
[my_stoi] mean-time: 38.85 ns, std-dev: 7.40463 ns
[std::stoi] mean-time: 106.28 ns, std-dev: 7.32189 ns
```

my_stoi was faster for sure in this test.

## :clock1: Converting double to string and back

:construction:

## :clock1: Count occurances

:construction:

# Usage

Compiler:  gcc (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders) 10.2.0

Build with gcc
```
 $ gcc main.cpp -std=c++17 -o2 -o main
```

Build with CMake.
```
 $ mkdir build && cd build
 $ cmake ..
 $ make
```

Running gen_img.py you will need Matplotlib

```
$ python gen_img.py int_to_string.csv int_to_string.jpg
```

# License

WTFPL