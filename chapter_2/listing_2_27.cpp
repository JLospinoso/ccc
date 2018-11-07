#include <cstdio>

struct Taxonomist {
  Taxonomist() {
    printf("(no argument)\n");
  }
  Taxonomist(char x) {
    printf("char: %c\n", x);
  }
  Taxonomist(int x) {
    printf("int: %d\n", x);
  }
  Taxonomist(float x) {
    printf("float: %f\n", x);
  }
};

int main() {
  Taxonomist t1;
  Taxonomist t2{ 'c' };
  Taxonomist t3{ 65537 };
  Taxonomist t4{ 6.02e23f };
  Taxonomist t5('g');
  Taxonomist t6 = { 'l' };
  Taxonomist t7{};
  Taxonomist t8();
}
