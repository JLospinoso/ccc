set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)

include_directories(${Boost_INCLUDE_DIR} googletest/googletest/include googletest/googlemock/include)

add_executable(austere austere/main.cpp)
add_executable(catch catch/tests.cpp catch/catch.hpp)
add_executable(boost_all boost/tests.cpp)
add_executable(boost_min boost/minimal.cpp)
add_executable(catch_min catch/minimal.cpp catch/catch.hpp)
add_executable(gtest_min gtest/minimal.cpp)
add_executable(gtest_all gtest/main.cpp)

target_link_libraries(boost_all ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(boost_min ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(gtest_all gtest_main gmock gtest)
target_link_libraries(gtest_min gtest_main gmock gtest)
