#include <cstdio>

namespace Creature {
struct Jabberwock {
  void* tulgey_wood;
  int is_galumphing;
};
} // namespace Creature

namespace Func {
void Jabberwock() {
  printf("Burble!");
}
} // namespace Func

using namespace Creature;

int main() {
  Jabberwock x;
  Func::Jabberwock();
}
