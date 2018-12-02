#include <cstdio>

int add_one_to(int x) {
  x++;
  return x;
}

int main() {
  auto original = 1;
  auto result = add_one_to(original);
  printf("Original: %d; Result: %d", original, result);
  return 0;
}
