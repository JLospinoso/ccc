#include <cstdio>
#include <string>

int main() {
  std::string word("pulchritudinous");
  printf("c_str: %s at 0x%p\n", word.c_str(), word.c_str());
  printf("data:  %s at 0x%p\n", word.data(), word.data());
}