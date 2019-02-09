#include <cstdio>

int main() {
  auto increment = [](auto x, int y = 1) { return x + y; };
  printf("increment(10)    = %d\n", increment(10));
  printf("increment(10, 5) = %d\n", increment(10, 5));
}
