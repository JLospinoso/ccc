cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_10 LANGUAGES CXX)

#######################
# Tests using Austere #
#######################

macro(austeretest_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

austeretest_add_test(austere austere/main.cpp)

#############################
# Tests using Boost Library #
#############################

boosttest_add_test(boost_all boost/tests.cpp)
boosttest_add_test(boost_min boost/minimal.cpp)

###################################
# Tests using Google Test Library #
###################################

googletest_add_test(gtest_all gtest/main.cpp)
googletest_add_test(gtest_min gtest/minimal.cpp)

#############################
# Tests using Catch Library #
#############################

catch_add_test(catch catch/tests.cpp)
catch_add_test(catch_min catch/minimal.cpp)