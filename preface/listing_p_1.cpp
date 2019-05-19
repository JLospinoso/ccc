#include <cstdio>

constexpr int isqrt(int n) {
  int i = 1;
  while(i * i < n)
    ++i;
  return i - (i * i != n);
}

int main() {
  constexpr int x = isqrt(1764);
  printf("%d", x);
}
