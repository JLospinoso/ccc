#include <cstdint>
#include <cstdio>

int main() {
  int32_t a = 100;
  int64_t b{ a };
  if(a == b)
    printf("Non-narrowing conversion!\n");
  //int32_t c{ b }; // Bang!
}
