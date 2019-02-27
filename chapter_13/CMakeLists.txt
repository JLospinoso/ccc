cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_13 LANGUAGES CXX)

add_executable(associative_containers associative_containers.cpp)
add_executable(graph graph.cpp)
add_executable(ptree ptree.cpp)
add_executable(sequential_containers sequential_containers.cpp)


target_link_libraries(associative_containers PRIVATE Catch2)
target_link_libraries(graph PRIVATE Catch2)
target_link_libraries(ptree PRIVATE Catch2)
target_link_libraries(sequential_containers PRIVATE Catch2)
