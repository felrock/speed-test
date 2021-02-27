# my_func vs std::func

This repo holds code for investigating if a simple or novice implementation of a given function is "faster" than the standard library functions that are available. I placed faster in quotation marks since this is only an estimation and not an exact science, this is just for fun. Each function pair that I put in a 1 v 1 battle are displayed under *Cases* below.


All **my_func** methods are implemented with both simplicity and speed in mind, where simplicity is the more important category in my opinion. Because in a realistic senario I wouldn't spend to much time on optimizing a to_string method for example.

# Cases

## my_to_string v.s std::to_string

```
[std::to_string] mean-time: 55.03 ns, std-dev: 0.0846399 ns
[my_to_string] mean-time: 94.06 ns, std-dev: 0.194284 ns
```

std::string is faster for sure in this test.


## my_stoi v.s std::stoi
```
[my_stoi] mean-time: 44.65 ns, std-dev: 0.129752 ns
[std::stoi] mean-time: 108.47 ns, std-dev: 0.155168 ns
```

my_stoi was faster for sure in this test.


## Usage

Compiler:  gcc (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders) 10.2.0

Build with CMake.
´´´
mkdir build && cd build
cmake ..
make
´´´