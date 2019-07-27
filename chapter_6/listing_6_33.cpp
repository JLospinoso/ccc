#include <cstdio>
#include <stdexcept>

int& get_from_int10(int (&arr)[10], size_t index) {
  if(index >= 10)
    throw std::out_of_range{ "Out of bounds" };
  return arr[index];
}

template <typename T>
T& get_from_array10(T (&arr)[10], size_t index) {
  if(index >= 10)
    throw std::out_of_range{ "Out of bounds" };
  return arr[index];
}

template <typename T, size_t Length>
T& get_throw(T (&arr)[10], size_t index) {
  if(index >= 10)
    throw std::out_of_range{ "Out of bounds" };
  return arr[index];
}

template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
  static_assert(Index < Length, "Out of bounds access");
  return arr[Index];
}

int main() {
  int fib[]{ 1, 1, 2, 0 };
  printf("%d %d %d ", get<0>(fib), get<1>(fib), get<2>(fib));
  get<3>(fib) = get<1>(fib) + get<2>(fib);
  printf("%d", get<3>(fib));
  // printf("%d", get<4>(fib));
}
