add_executable(complex complex.cpp)
add_executable(container container.cpp)
add_executable(data_structs data_structs.cpp)
add_executable(rand rand.cpp)
add_executable(smart_ptrs smart_ptrs.cpp)
add_executable(time time.cpp)

target_link_libraries(time LINK_PUBLIC ${Boost_LIBRARIES})
