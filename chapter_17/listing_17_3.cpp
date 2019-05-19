#include <filesystem>
#include <iostream>

using namespace std;

int main() {
  filesystem::path path{ R"(C:/Windows/System32/kernel32.dll)" };
  cout << path << endl;

  path.make_preferred();
  cout << path << endl;

  path.replace_filename("win32kfull.sys");
  cout << path << endl;

  path.remove_filename();
  cout << path << endl;

  path.clear();
  cout << "Is empty: " << boolalpha << path.empty() << endl;
}
