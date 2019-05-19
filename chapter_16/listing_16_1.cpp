#include <bitset>
#include <iostream>
#include <string>

using namespace std;

int main() {
  bitset<8> s{ "01110011" };
  string str("Crying zeros and I'm hearing ");
  size_t num{ 111 };
  cout << s;
  cout << '\n';
  cout << str;
  cout << num;
  cout << "s\n";
}