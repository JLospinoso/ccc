#include <cstdint>
#include <cstdio>
#include <origin/core/concepts.hpp>

struct Goblin {};


size_t index_of_minimum(Ordered* x, size_t length) {
  size_t min_index{};
  for(size_t i{ 1 }; i < length; i++) {
    if(x[i] < x[min_index])
      min_index = i;
  }
  return min_index;
}

int main() {
  int x1[]{ -20, 0, 100, 400, -21, 5123 };
  printf("%zd\n", index_of_minimum(x1, 6));

  unsigned short x2[]{ 42, 51, 900, 400 };
  printf("%zd\n", index_of_minimum(x2, 4));

  Goblin x3[]{ Goblin{}, Goblin{} };
  //index_of_minimum(x3, 2); // Bang! Goblin is not Ordered.
}
