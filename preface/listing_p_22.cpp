#include <cstdio>

struct Hal {
  Hal()
      : version{ 9000 } { // Constructor
    printf("I'm completely operational.\n");
  }
  ~Hal() { // Destructor
    printf("Stop, Dave.\n");
  }
  const int version;
};

int main() {
  auto hal = new Hal{}; // Memory is allocated, then constructor is called
  delete hal; // Destructor is called, then memory is deallocated
}
