#include <cstdint>
#include <cstdio>

bool double_return_overflow(uint8_t& x) {
  const auto original = x;
  x *= 2;
  return original > x;
}

int main() {
  uint8_t x{ 1 };
  printf("uint8_t:\n===\n");
  while(!double_return_overflow(x)) {
    printf("%u ", x);
  }
}
