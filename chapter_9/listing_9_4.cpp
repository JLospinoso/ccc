#include <cstdio>

template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y) {
  return x + y;
}

int main() {
  auto my_double = add(100., -10);
  printf("decltype(double + int) = double; %f\n", my_double);

  auto my_uint = add(100U, -20);
  printf("decltype(uint + int) = uint; %u\n", my_uint);

  auto my_ulonglong = add(char{ 100 }, 54'999'900ull);
  printf("decltype(char + ulonglong) = ulonglong; %llu\n", my_ulonglong);
}
