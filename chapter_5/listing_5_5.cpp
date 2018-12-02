#include <cstdio>

int main() {
  auto timer = reinterpret_cast<const unsigned long*>(0x1000);
  printf("Timer is %lu.", *timer);
}
