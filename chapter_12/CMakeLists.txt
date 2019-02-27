add_executable(complex complex.cpp catch.hpp)
add_executable(container container.cpp catch.hpp)
add_executable(data_structs data_structs.cpp catch.hpp)
add_executable(rand rand.cpp catch.hpp)
add_executable(smart_ptrs smart_ptrs.cpp catch.hpp)
add_executable(time time.cpp catch.hpp)

target_link_libraries(iterators ${Boost_SYSTEM_LIBRARY})