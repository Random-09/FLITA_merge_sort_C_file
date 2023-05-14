cmake_minimum_required(VERSION 3.24)
project(FLITA_merge_sort_C_file C)

set(CMAKE_C_STANDARD 11)

add_executable(FLITA_merge_sort_C_file main.c merge_sort.c merge_sort.h)
