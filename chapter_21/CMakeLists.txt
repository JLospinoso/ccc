cmake_minimum_required(VERSION 3.1...3.13)

project(chapter_21 LANGUAGES CXX)

add_executable(atexit atexit.cpp)
add_executable(abort abort.cpp)
add_executable(exit exit.cpp)
# add_executable(quickexit quickexit.cpp)
add_executable(ping ping.cpp)
add_executable(getenv getenv.cpp)
add_executable(sigint sigint.cpp)
add_executable(dedication dedication.cpp)
add_executable(program_options program_options.cpp)

target_link_libraries(program_options ${Boost_LIBRARIES})
