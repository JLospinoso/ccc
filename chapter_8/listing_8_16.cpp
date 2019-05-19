#include <cstdio>

struct TextFile {
  bool success;
  const char* data;
  size_t n_bytes;
};

TextFile read_text_file(const char* path) {
  const static char contents[]{ "Sometimes the goat is you." };
  return TextFile{ true, contents, sizeof(contents) };
}

int main() {
  if(const auto [success, contents, length] = read_text_file("REAMDE.txt"); success) {
    printf("Read %zd bytes: %s\n", length, contents);
  } else {
    printf("Failed to open REAMDE.txt.");
  }
}
