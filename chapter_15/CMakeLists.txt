cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_15 LANGUAGES CXX)

add_executable(strings strings.cpp)
add_executable(c_str_example c_str_example.cpp)

target_link_libraries(strings PRIVATE Catch2 ${Boost_SYSTEM_LIBRARY})
