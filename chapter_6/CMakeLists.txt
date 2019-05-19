cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_6 LANGUAGES CXX)

add_executable(listing_6_4 listing_6_4.cpp)
add_executable(listing_6_5 listing_6_5.cpp)
add_executable(listing_6_7 listing_6_7.cpp)
add_executable(listing_6_11 listing_6_11.cpp)
add_executable(listing_6_13 listing_6_13.cpp)
add_executable(listing_6_15 listing_6_15.cpp)
add_executable(listing_6_17 listing_6_17.cpp)
add_executable(listing_6_18 listing_6_18.cpp)
add_executable(listing_6_33 listing_6_33.cpp)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_executable(listing_6_21 listing_6_21.cpp)
    add_executable(listing_6_22 listing_6_22.cpp)
    target_compile_options(listing_6_21 PUBLIC -fconcepts)
    target_compile_options(listing_6_22 PUBLIC -fconcepts)
    # TODO:
    # add_executable(listing_6_26 listing_6_26.cpp)
    # target_compile_options(listing_6_26 PUBLIC -fconcepts)
endif()
