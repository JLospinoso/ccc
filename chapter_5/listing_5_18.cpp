#include <type_traits>
#include <cstdio>
#include <cstdint>

const char* as_str(bool x) { return x ? "True" : "False"; }

using namespace std;

int main() {
  printf("%s\n", as_str(is_integral<int>::value));
  printf("%s\n", as_str(is_integral<const int>::value));
  printf("%s\n", as_str(is_integral<char>::value));
  printf("%s\n", as_str(is_integral<uint64_t>::value));
  printf("%s\n", as_str(is_integral<int&>::value));
  printf("%s\n", as_str(is_integral<int*>::value));
  printf("%s\n", as_str(is_integral<float>::value));
}
