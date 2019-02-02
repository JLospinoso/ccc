cmake_minimum_required (VERSION 3.11)

project(ccc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

add_subdirectory(chapter_1)
add_subdirectory(chapter_2)
add_subdirectory(chapter_3)
add_subdirectory(chapter_4)
add_subdirectory(chapter_5)
add_subdirectory(chapter_6)
add_subdirectory(chapter_7)
