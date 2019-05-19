cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_14 LANGUAGES CXX)

catch_add_test(iterators iterators.cpp)

target_link_libraries(iterators PRIVATE ${Boost_SYSTEM_LIBRARY})
