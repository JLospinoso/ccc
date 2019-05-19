cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_18 LANGUAGES CXX)

if(MSVC) # Some compilers don't have complete C++17 <numerics>, <algorithms> support
    catch_add_test(algorithms algorithms.cpp)
    target_link_libraries(algorithms PRIVATE ${Boost_SYSTEM_LIBRARY})
    catch_add_test(numerics numerics.cpp)
endif()
add_executable(sample sample.cpp)
add_executable(shuffle shuffle.cpp)
add_executable(explore explore.cpp)

