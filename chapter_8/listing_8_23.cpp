#include <cstdio>

int main() {
  int x[]{ 1, 1, 2, 3, 5, 8 };
  for (auto element : x) {
    printf("%d ", element);
  }
}
