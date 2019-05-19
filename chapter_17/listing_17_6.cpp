#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;
using namespace std::chrono;

void write_info(const path& p) {
  if(!exists(p)) {
    cout << p << " does not exist." << endl;
    return;
  }
  const auto last_write = last_write_time(p).time_since_epoch();
  const auto in_hours = duration_cast<hours>(last_write).count();
  cout << p << "\t" << in_hours << "\t" << file_size(p) << "\n";
}

int main() {
  const path win_path{ R"(C:/Windows/System32/kernel32.dll)" };
  const auto reamde_path = temp_directory_path() / "REAMDE";
  try {
    write_info(win_path);
    write_info(reamde_path);

    cout << "Copying " << win_path.filename() << " to " << reamde_path.filename() << "\n";
    copy_file(win_path, reamde_path);
    write_info(reamde_path);

    cout << "Resizing " << reamde_path.filename() << "\n";
    resize_file(reamde_path, 1024);
    write_info(reamde_path);

    cout << "Removing " << reamde_path.filename() << "\n";
    remove(reamde_path);
    write_info(reamde_path);
  } catch(const exception& e) {
    cerr << "Exception: " << e.what() << endl;
  }
}