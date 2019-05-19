#include <algorithm>
#include <iostream>
#include <string>

int main() {
  auto i{ 28'939'844 };
  std::string x{ " DFaeeillnor" };
  while(i--)
    std::next_permutation(x.begin(), x.end());
  std::cout << x;
}
