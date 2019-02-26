cmake_minimum_required(VERSION 3.1...3.13)

project(ccc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

#################
# Boost Library #
#################

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTI_THREADED ON)
# set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost 1.60 REQUIRED COMPONENTS date_time system filesystem unit_test_framework)

include_directories(${Boost_INCLUDE_DIR})

macro(boosttest_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE ${Boost_FILESYSTEM_LIBRARY}
                                PRIVATE ${Boost_SYSTEM_LIBRARY}
                                PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

#######################
# Google Test Library #
#######################

add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/google/googletest" "third_party/google/googletest")
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

set_target_properties(gtest PROPERTIES FOLDER third_party)
set_target_properties(gtest_main PROPERTIES FOLDER third_party)
set_target_properties(gmock PROPERTIES FOLDER third_party)
set_target_properties(gmock_main PROPERTIES FOLDER third_party)

macro(googletest_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE gtest PRIVATE gmock PRIVATE gtest_main)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

#################
# Catch Library #
#################

add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE ${CMAKE_SOURCE_DIR}/third_party/catchorg/Catch2/single_include)

macro(catch_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE Catch2)
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
