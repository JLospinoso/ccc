cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_13 LANGUAGES CXX)

catch_add_test(associative_containers associative_containers.cpp)
catch_add_test(graph graph.cpp)
catch_add_test(ptree ptree.cpp)
catch_add_test(sequential_containers sequential_containers.cpp)
