#include <iostream>
#include <string>

int main() {
  std::string word;
  size_t count{};
  while(std::cin >> word) {
    count++;
  }
  std::cout << "Discovered " << count << " words.\n";
}