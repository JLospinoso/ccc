#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

ifstream open(const char* path, ios_base::openmode mode = ios_base::in) {
  ifstream file{ path, mode };
  if(!file.is_open()) {
    string err{ "Unable to open file " };
    err.append(path);
    throw runtime_error{ err };
  }
  file.exceptions(ifstream::badbit);
  return file;
}

int main() {
  auto file = open("numbers.txt");
  auto maximum = numeric_limits<int>::min();
  int value;
  while(file >> value)
    maximum = maximum < value ? value : maximum;
  cout << "Maximum found was " << maximum << endl;
}
