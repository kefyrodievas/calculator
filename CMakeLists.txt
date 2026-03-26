cmake_minimum_required(VERSION 4.1)
project(calculator C)

set(CMAKE_C_STANDARD 11)
add_executable(calculator main.c
        eval.c
        eval.h
        stack.c
        stack.h
        token.c
        token.h)

target_link_libraries(calculator m)
