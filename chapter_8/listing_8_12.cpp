#include <cstdio>
#include <stdexcept>

[[noreturn]] void pitcher() {
  throw std::runtime_error{ "Knuckleball." };
}

int main() {
  try {
    pitcher();
  } catch(const std::exception& e) {
    printf("exception: %s\n", e.what());
  }
}
