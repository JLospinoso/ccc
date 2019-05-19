#include <cstdio>

int main() {
  const int x[]{ 1, 1, 2, 3, 5, 8 };
  printf("i: x[i]\n");
  for(int i{}; i < 6; i++) {
    printf("%d: %d\n", i, x[i]);
  }
}
