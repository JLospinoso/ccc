#include <cstdio>

struct Tracer {
  Tracer(const char* name) : name{ name } {
    printf("%s constructed.\n", name);
  }
  ~Tracer() {
    printf("%s destructed.\n", name);
  }
private:
  const char* const name;
};

int main() {
  Tracer main{ "main" };
  {
    printf("Block a\n");
    Tracer a1{ "a1" };
    Tracer a2{ "a2" };
  }
  {
    printf("Block b\n");
    Tracer b1{ "b1" };
    Tracer b2{ "b2" };
  }
}