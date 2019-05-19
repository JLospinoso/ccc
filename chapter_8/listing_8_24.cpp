#include <cstdio>

int main() {
  const int x[]{ 1, 1, 2, 3, 5, 8 };
  for(const auto element : x) {
    printf("%d ", element);
  }
}
