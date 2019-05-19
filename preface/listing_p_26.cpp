#include <memory>

struct Foundation {
  const char* founder;
};

int main() {
  std::unique_ptr<Foundation> second_foundation{ new Foundation{} };
  // Access Foo member variable just like a pointer
  second_foundation->founder = "Wanda";
}
