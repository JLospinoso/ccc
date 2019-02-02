#include <cstdio>

struct BaseClass {
  virtual const char* final_message() const {
    return "We apologise for the incontinence.";
  }
};

struct DerivedClass : BaseClass {
  const char* final_message() const override {
    return "We apologise for the inconvenience.";
  }
};

int main() {
  BaseClass base;
  DerivedClass derived;
  BaseClass& ref = derived;
  printf("BaseClass:    %s\n", base.final_message());
  printf("DerivedClass: %s\n", derived.final_message());
  printf("BaseClass&:   %s\n", ref.final_message());
}
