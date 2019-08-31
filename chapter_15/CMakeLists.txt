cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_15 LANGUAGES CXX)

catch_add_test(strings strings.cpp)
add_executable(c_str_example c_str_example.cpp)

target_link_libraries(strings PRIVATE CONAN_PKG::boost)
