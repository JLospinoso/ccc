#include <cstdio>

struct BostonCorbett {
  virtual void shoot() final {
    printf("What a God we have...God avenged Abraham Lincoln");
  }
};

struct BostonCorbettJunior : BostonCorbett {
  //void shoot() override {} // Bang! shoot is final.
};

int main() {
  BostonCorbettJunior junior;
}
