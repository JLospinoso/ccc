#include <filesystem>
#include <fstream>
#include <iostream>
#include <unordered_set>

using namespace std;
using namespace std::filesystem;

int main(int argc, const char** argv) {
  if(argc != 2) {
    cerr << "Usage: pecheck PATH";
    return -1;
  }
  const unordered_set<string> pe_extensions{ ".acm", ".ax",  ".cpl", ".dll", ".drv", ".efi",
                                             ".exe", ".mui", ".ocx", ".scr", ".sys", ".tsp" };
  const path sys_path{ argv[1] };
  cout << "Searching " << sys_path << " recursively.\n";
  size_t n_searched{};
  auto iterator = recursive_directory_iterator{ sys_path, directory_options::skip_permission_denied };
  for(const auto& entry : iterator) {
    try {
      if(!entry.is_regular_file())
        continue;
      const auto& extension = entry.path().extension().string();
      const auto is_pe = pe_extensions.find(extension) != pe_extensions.end();
      if(!is_pe)
        continue;
      ifstream file{ entry.path() };
      char first{}, second{};
      if(file)
        file >> first;
      if(file)
        file >> second;
      if(first != 'M' || second != 'Z')
        cout << "Invalid PE found: " << entry.path().string() << "\n";
      ++n_searched;
    } catch(const exception& e) {
      cerr << "Error reading " << entry.path().string() << ": " << e.what() << endl;
    }
  }
  cout << "Searched " << n_searched << " PEs for magic bytes." << endl;
}