cmake_minimum_required(VERSION 4.2)
project(calculator_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(calculator_cpp main.cpp
        eval.cpp
        stack.cpp
        token.cpp)

add_executable(runTests tests.cpp
        eval.cpp
        stack.cpp
        token.cpp
)
target_link_libraries(runTests gtest gtest_main)
add_test(NAME runTests COMMAND runTests)

target_link_libraries(calculator_cpp m)