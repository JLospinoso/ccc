#include <cstdio>
#include <limits>

int main() {
  double x = std::numeric_limits<float>::max();
  long double y = std::numeric_limits<double>::max();
  float z = std::numeric_limits<long double>::max(); // Undefined Behavior
  printf("x: %g\ny: %g\nz: %g");
}
