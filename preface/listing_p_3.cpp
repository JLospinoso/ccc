char* toa(int value, char* buffer, int base) {
  return nullptr;
}

char* toa(long value, char* buffer, int base) {
  return nullptr;
}

char* toa(unsigned long value, char* buffer, int base) {
  return nullptr;
}

int main() {
  char buff[10];
  int a = 1;
  long b = 2;
  unsigned long c = 3;
  toa(a, buff, 10);
  toa(b, buff, 10);
  toa(c, buff, 10);
}
