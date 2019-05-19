struct BaseClass {};
struct DerivedClass : BaseClass {};
void all_about_that(DerivedClass& derived) {}

int main() {
  BaseClass base;
  //all_about_that(base); // No! Trouble!
}
