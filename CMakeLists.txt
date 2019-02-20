cmake_minimum_required (VERSION 3.11)

project(ccc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTI_THREADED ON)
#?? set(Boost_USE_STATIC_RUNTIME TRUE)
find_package(Boost COMPONENTS date_time system filesystem unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
include_directories(catch)

add_subdirectory(chapter_1)
add_subdirectory(chapter_2)
add_subdirectory(chapter_3)
add_subdirectory(chapter_4)
add_subdirectory(chapter_5)
add_subdirectory(chapter_6)
add_subdirectory(chapter_7)
add_subdirectory(chapter_8)
add_subdirectory(chapter_9)
add_subdirectory(chapter_10)
add_subdirectory(chapter_11)
