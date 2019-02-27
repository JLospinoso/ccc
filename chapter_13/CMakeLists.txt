cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_13 LANGUAGES CXX)

add_executable(associative_containers associative_containers.cpp catch.hpp)
add_executable(graph graph.cpp catch.hpp)
add_executable(ptree ptree.cpp catch.hpp)
add_executable(sequential_containers sequential_containers.cpp catch.hpp)