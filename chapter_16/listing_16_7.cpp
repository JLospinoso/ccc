#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.exceptions(istream::badbit);
  string word;
  size_t count{};
  try {
    while(cin >> word)
      count++;
    cout << "Discovered " << count << " words.\n";
  } catch(const std::exception& e) {
    cerr << "Error occurred reading from stdin: " << e.what();
  }
}