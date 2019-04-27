#include <memory>

struct Foo{
  int foo_element{};
};

int main() {
  std::unique_ptr<Foo> foo_ptr{ new Foo{} };
  // ...
  foo_ptr->foo_element++; // Access Foo member variable just like a pointer
}
