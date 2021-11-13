project(beat-std)

add_executable(main src/main.cpp)
add_executable(unittest src/test.cpp)

set(CMAKE_CXX_STANDRAD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
