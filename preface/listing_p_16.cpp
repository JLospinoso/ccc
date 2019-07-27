#include <cstddef>

int main() {
  const size_t n = 100;
  int v[n];

  // ANSI-C
  size_t i;
  for(i = 0; i < n; i++)
    v[i] = 0;

  // C99
  for(size_t i = 0; i < n; i++)
    v[i] = 0;

  // C++17
  for(auto& x : v)
    x = 0;
}
