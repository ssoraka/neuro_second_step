cmake_minimum_required(VERSION 3.17)
project(neuro_second C)

set(CMAKE_C_STANDARD 99)

add_executable(neuro_second main.c header.h)
target_link_libraries(neuro_second m)