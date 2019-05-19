#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
  SimpleString(size_t max_size)
      : max_size{ max_size }
      , length{} {
    if(max_size == 0) {
      throw std::runtime_error{ "Max size must be at least 1." };
    }
    buffer = new char[max_size];
    buffer[0] = 0;
  }
  ~SimpleString() {
    delete[] buffer;
  }
  void print(const char* tag) const {
    printf("%s: %s", tag, buffer);
  }
  bool append_line(const char* x) {
    const auto x_len = strlen(x);
    if(x_len + length + 2 > max_size)
      return false;
    strncpy(buffer + length, x, max_size - length);
    length += x_len;
    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
  }

  private:
  size_t max_size;
  char* buffer;
  size_t length;
};

struct SimpleStringOwner {
  SimpleStringOwner(const char* x)
      : string{ 10 } {
    if(!string.append_line(x)) {
      throw std::runtime_error{ "Not enough memory!" };
    }
    string.print("Constructed");
  }
  ~SimpleStringOwner() {
    string.print("About to destroy");
  }

  private:
  SimpleString string;
};

int main() {
  SimpleStringOwner x{ "x" };
  printf("x is alive\n");
  return 0;
}
