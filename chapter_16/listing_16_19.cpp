#include <exception>
#include <fstream>
#include <iostream>

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
  try {
    auto intro = open("introspection.txt");
    cout << "Contents: " << intro.rdbuf() << endl;
    intro.seekg(0);
    cout << "Contents after seekg(0): " << intro.rdbuf() << endl;
    intro.seekg(-4, ios_base::end);
    cout << "tellg() after seekg(-4, ios_base::end): " << intro.tellg() << endl;
    cout << "Contents after seekg(-4, ios_base::end): " << intro.rdbuf() << endl;
  } catch(exception& e) {
    cerr << e.what();
  }
}
