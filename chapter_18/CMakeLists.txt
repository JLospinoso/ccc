cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_18 LANGUAGES CXX)

catch_add_test(algorithms algorithms.cpp)
if(MSVC) # Some compilers don't yet implement <numerics>
    catch_add_test(numerics numerics.cpp)
endif()
add_executable(sample sample.cpp)
add_executable(shuffle shuffle.cpp)
add_executable(explore explore.cpp)

target_link_libraries(algorithms PRIVATE ${Boost_SYSTEM_LIBRARY})
