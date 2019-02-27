cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_12 LANGUAGES CXX)

add_executable(complex complex.cpp)
add_executable(container container.cpp)
add_executable(data_structs data_structs.cpp)
add_executable(rand rand.cpp)
add_executable(time time.cpp)

target_link_libraries(complex PRIVATE Catch2)
target_link_libraries(container PRIVATE Catch2)
target_link_libraries(data_structs PRIVATE Catch2)
target_link_libraries(rand PRIVATE Catch2)
target_link_libraries(time PRIVATE Catch2 ${Boost_LIBRARIES})
