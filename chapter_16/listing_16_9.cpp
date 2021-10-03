#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  s << "Size: " << v.size() << "\nCapacity: " << v.capacity() << "\nElements:\n";
  for(const auto& element : v)
    s << "\t" << element << "\n";
  return s;
}

int main() {
  const vector<string> characters{ "Bobby Shaftoe", "Lawrence Waterhouse", "Gunter Bischoff", "Earl Comstock" };
  cout << "vector<string> characters:\n" << characters << endl;

  const vector<bool> bits{ true, false, true, false };
  cout << boolalpha << bits << endl;
}