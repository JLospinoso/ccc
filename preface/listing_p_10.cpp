#include <cstdlib>

struct FooBar {};

FooBar* make_foobar(char x) {
  return (FooBar*)malloc(sizeof(FooBar));
}

int main() {
  auto foo = make_foobar('z');
  free(foo);
}
