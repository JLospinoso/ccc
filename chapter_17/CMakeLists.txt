cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_17 LANGUAGES CXX)

catch_add_test(filesystem filesystem.cpp)
add_executable(listing_17_2 listing_17_2.cpp)
add_executable(listing_17_3 listing_17_3.cpp)
add_executable(listing_17_4 listing_17_4.cpp)
add_executable(listing_17_5 listing_17_5.cpp)
add_executable(listing_17_6 listing_17_6.cpp)
add_executable(listing_17_7 listing_17_7.cpp)
add_executable(listing_17_8 listing_17_8.cpp)
add_executable(listing_17_9 listing_17_9.cpp)

target_link_libraries(filesystem PRIVATE ${Boost_SYSTEM_LIBRARY})
