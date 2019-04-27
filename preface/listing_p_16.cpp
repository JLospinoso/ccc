#include <cstddef>

int main() {
  const size_t n{ 100 };
  int v[n];

  // ANSI-C
  int i;
  for (i=0; i<n; i++) v[i] = 0;

  // C99
  for (int i=0; i<n; i++)  v[i] = 0;

  // C++17
  for (auto& x : v) x = 0;
}
