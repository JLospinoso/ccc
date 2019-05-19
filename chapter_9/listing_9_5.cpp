#include <cstdarg>
#include <cstdint>
#include <cstdio>

int sum(size_t n, ...) {
  va_list args;
  va_start(args, n);
  int result{};
  while(n--) {
    auto next_element = va_arg(args, int);
    result += next_element;
  }
  va_end(args);
  return result;
}

int main() {
  printf("The answer is %d.", sum(6, 2, 4, 6, 8, 10, 12));
}
