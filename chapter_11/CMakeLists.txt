cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_11 LANGUAGES CXX)

add_executable(smart_ptrs smart_ptrs.cpp)

target_link_libraries(smart_ptrs PRIVATE Catch2)
