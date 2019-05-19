#include <cstdio>
#include <cstring>
#include <system_error>

struct File {
  File(const char* path, bool write) {
    auto file_mode = write ? "w" : "r";
    file_pointer = fopen(path, file_mode);
    if(!file_pointer)
      throw std::system_error(errno, std::system_category());
  }
  ~File() {
    fclose(file_pointer);
  }
  FILE* file_pointer;
};

int main() {
  {
    File file("last_message.txt", true);
    const auto message = "We apologise for the inconvenience.";
    fwrite(message, strlen(message), 1, file.file_pointer);
  }
  // last_message.txt is closed here!
  {
    File file("last_message.txt", false);
    char read_message[37]{};
    fread(read_message, sizeof(read_message), 1, file.file_pointer);
    printf("Read last message: %s\n", read_message);
  }
}
