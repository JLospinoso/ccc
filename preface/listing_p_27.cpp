#include <memory>

struct Foundation {
  const char* founder;
};

struct Mutant {
  // Constructor sets foundation appropriately:
  Mutant(std::unique_ptr<Foundation> foundation)
      : foundation(move(foundation)) {}
  std::unique_ptr<Foundation> foundation;
};

int main() {
  std::unique_ptr<Foundation> second_foundation{ new Foundation{} };
  // ... use second_foundation
  Mutant the_mule{ std::move(second_foundation) };
  // second_foundation is in a 'moved-from' state
  // the_mule owns the Foundation
}
