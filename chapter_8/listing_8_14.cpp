#include <cstdio>

template <typename T>
constexpr const char* sign(const T& x) {
  const char* result{};
  if(x == 0) {
    result = "zero";
  } else if(x > 0) {
    result = "positive";
  } else {
    result = "negative";
  }
  return result;
}

int main() {
  printf("float 100 is %s\n", sign(100.0f));
  printf("int  -200 is %s\n", sign(-200));
  printf("char    0 is %s\n", sign(char{}));
}
