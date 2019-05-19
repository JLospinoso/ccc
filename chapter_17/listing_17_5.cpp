#include <filesystem>
#include <iostream>

using namespace std;

void describe(const filesystem::path& p) {
  cout << boolalpha << "Path: " << p << endl;
  try {
    cout << "Is directory: " << is_directory(p) << endl;
    cout << "Is regular file: " << is_regular_file(p) << endl;
  } catch(const exception& e) {
    cerr << "Exception: " << e.what() << endl;
  }
}

int main() {
  filesystem::path win_path{ R"(C:/Windows/System32/kernel32.dll)" };
  describe(win_path);
  win_path.remove_filename();
  describe(win_path);

  filesystem::path nix_path{ R"(/bin/bash)" };
  describe(nix_path);
  nix_path.remove_filename();
  describe(nix_path);
}