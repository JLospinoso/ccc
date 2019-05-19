#include <cstdint>
#include <cstdio>

int main(int argc, char** argv) {
  printf("Arguments: %d\n", argc);
  for(size_t i{}; i < argc; i++) {
    printf("%zd: %s\n", i, argv[i]);
  }
}
