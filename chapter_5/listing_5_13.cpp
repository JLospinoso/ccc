#include <cstddef>
#include <cstdio>

template<typename T>
T mean(T* values, size_t length) {
  T result{};
  for (size_t i{}; i<length; i++) {
    result += values[i];
  }
  return result / length;
}

int main() {
  auto value1 = 0.0;
  auto value2 = 1.0;
  double* values[]{ &value1, &value2 };
  //mean(values, 2); // Bang!
}
