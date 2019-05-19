#include <cstddef>
#include <cstdio>
#include <type_traits>

template <typename T>
concept bool Averageable() {
  return std::is_default_constructible<T>::value && std::is_copy_constructible<T>::value && requires(T a, T b) {
    { a + b }
    ->T;
    { a / b }
    ->T;
  };
}

template <Averageable T>
T mean(const T* values, size_t length) {
  T result{};
  for(size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}

int main() {
  auto value1 = 0.0;
  auto value2 = 1.0;
  const double* values[]{ &value1, &value2 };
  // mean(values, 2); // Causes compiler error.
}
