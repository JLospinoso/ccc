#include <cstdio>

struct Hal {
  Hal() { // Constructor
    printf("I'm completely operational.\n");
    version = 9000;
  }
  ~Hal() { // Destructor
    printf("Stop, Dave.\n");
  }
  int version;
};

int main() {
  auto hal = new Hal{};  // Memory is allocated, then constructor is called
  delete hal;            // Destructor is called, then memory is deallocated
}
