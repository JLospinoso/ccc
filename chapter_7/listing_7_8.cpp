#include <cstdint>
#include <cstdio>

int main() {
  // 0b111111111 = 511
  uint8_t x = 0b111111111; // 255
  int8_t y = 0b111111111; // Implementation defined.
  printf("x: %u\ny: %d", x, y);
}
