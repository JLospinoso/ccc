#include <memory>

struct Foo {};

struct Bar {
  Bar(std::unique_ptr<Foo> foo_ptr)
    : foo_ptr(move(foo_ptr)) {} // Constructor sets foo_ptr appropriately
  std::unique_ptr<Foo> foo_ptr;
};

int main() {
  std::unique_ptr<Foo> foo_ptr{ new Foo{} };
  // ... use foo_ptr
  Bar bar(move(foo_ptr));
  // ... foo_ptr is in a 'moved-from' state; bar owns the Foo*
}
