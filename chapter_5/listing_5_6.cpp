#include <cstdio>

struct BaseClass {
  int the_answer() const { return 42; }
  const char* member = "gold";
private:
  const char* holistic_detective = "Dirk Gently";
};

struct DerivedClass : BaseClass {
  void announce_agency() {
    // This line doesn't compile:
    // printf("%s's Holistic Detective Agency\n", holistic_detective); {
  }
};

int main() {
  DerivedClass x;
  printf("The answer is %d\n", x.the_answer());
  printf("%s member\n", x.member);
}
