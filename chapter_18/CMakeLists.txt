cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_18 LANGUAGES CXX)

catch_add_test(algorithms algorithms.cpp)
catch_add_test(numerics numerics.cpp)
add_executable(sample sample.cpp)
add_executable(shuffle shuffle.cpp)
add_executable(explore explore.cpp)

target_link_libraries(algorithms PRIVATE ${Boost_SYSTEM_LIBRARY})
