#include <cstdio>

void trainwreck(const char* read_only) {
  //auto as_unsigned = reinterpret_cast<unsigned char*>(read_only);
  //*as_unsigned = 'b'; // Crashes on Windows 10 x64
}

int main() {
  auto ezra = "Ezra";
  printf("Before trainwreck: %s\n", ezra);
  trainwreck(ezra);
  printf("After trainwreck: %s\n", ezra);
}
