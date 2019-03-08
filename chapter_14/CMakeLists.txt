cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_14 LANGUAGES CXX)

add_executable(iterators iterators.cpp)

target_link_libraries(iterators PRIVATE ${Boost_SYSTEM_LIBRARY} Catch2)
