#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800 {
  CyberdyneSeries800() {
    printf("I'm a friend of Sarah Connor.");
  }
  ~CyberdyneSeries800() {
    throw std::runtime_error{ "I'll be back." };
  }
};

int main() {
  try {
    CyberdyneSeries800 t800;
    throw std::runtime_error{ "Come with me if you want to live." };
  } catch(const std::exception& e) {
    printf("Caught exception: %s\n", e.what());
  }
}
