#include <cstdio>
#include <functional>

void static_func() {
  printf("A static function.\n");
}

int main() {
  std::function<void()> func{ [] { printf("A lambda.\n"); } };
  func();
  func = static_func;
  func();
}
