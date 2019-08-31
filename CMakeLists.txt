cmake_minimum_required(VERSION 3.1...3.14)

project(ccc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(ENABLE_TESTS "Build test suite" ON)

# conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

include(GNUInstallDirs)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
endif(MSVC)

macro(boosttest_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE CONAN_PKG::boost)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

macro(googletest_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE CONAN_PKG::gtest)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

macro(catch_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE CONAN_PKG::Catch2 CONAN_PKG::boost)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

################
# Enable CTest #
################

enable_testing()

############
# Chapters #
############

add_subdirectory(preface)
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
add_subdirectory(chapter_12)
add_subdirectory(chapter_13)
add_subdirectory(chapter_14)
add_subdirectory(chapter_15)
add_subdirectory(chapter_16)
add_subdirectory(chapter_17)
add_subdirectory(chapter_18)
add_subdirectory(chapter_19)
add_subdirectory(chapter_20)
add_subdirectory(chapter_21)
