cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_12 LANGUAGES CXX)

add_executable(container container.cpp catch.hpp)
add_executable(data_structs data_structs.cpp catch.hpp)
add_executable(rand rand.cpp catch.hpp)
add_executable(smart_ptrs smart_ptrs.cpp catch.hpp)
add_executable(time time.cpp catch.hpp)