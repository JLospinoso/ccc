cmake_minimum_required(VERSION 3.1...3.14)

project(chapter_21 LANGUAGES CXX)

add_executable(atexit atexit.cpp)
add_executable(abort abort.cpp)
add_executable(exit exit.cpp)
if(MSVC)
    add_executable(quickexit quickexit.cpp)
endif(MSVC)
add_executable(ping ping.cpp)
add_executable(getenv getenv.cpp)
add_executable(sigint sigint.cpp)
add_executable(dedication dedication.cpp)

if(MSVC)
  add_executable(prog_ops program_options.cpp)
  target_link_libraries(prog_ops PRIVATE ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif(MSVC)
