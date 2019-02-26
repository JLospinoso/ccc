cmake_minimum_required (VERSION 3.1...3.13)

project(ccc LANGUAGES CXX)

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

add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE ${CMAKE_SOURCE_DIR}/third_party/catchorg/Catch2/single_include)

enable_testing()

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
