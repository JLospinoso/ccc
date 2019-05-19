#include <cstdio>

int main() {
  unsigned long maximum = 0;
  unsigned long values[] = { 10, 50, 20, 40, 0 };
  for(unsigned long value : values) {
    if(value > maximum)
      maximum = value;
  }
  printf("The maximum value is %lu.", maximum);
}
