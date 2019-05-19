#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  bitset<8> s{ "01110011" };
  string str("Crying zeros and I'm hearing ");
  size_t num{ 111 };
  cout << s << '\n' << str << num << "s\n";
}