cmake_minimum_required(VERSION 3.15)
project(my_som C)

set(CMAKE_C_STANDARD 99)

add_executable(my_som main.c data.h data.c list.h list.c)