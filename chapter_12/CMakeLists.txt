cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_12 LANGUAGES CXX)

catch_add_test(complex complex.cpp)
catch_add_test(data_structs data_structs.cpp)
catch_add_test(rand rand.cpp)

if(MSVC)
    catch_add_test(time time.cpp)
    target_link_libraries(time PRIVATE ${Boost_LIBRARIES})
endif(MSVC)
