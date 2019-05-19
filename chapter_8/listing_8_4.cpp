#include <cstdint>
#include <cstdio>

struct RandomNumberGenerator {
  explicit RandomNumberGenerator(uint32_t seed)
      : iterations{}
      , number{ seed } {}
  uint32_t next();
  size_t get_iterations() const;

  private:
  size_t iterations;
  uint32_t number;
};

int main() {
  RandomNumberGenerator rng{ 0x4c4347 };
  while(rng.next() != 0x474343) {
    // Do nothing...
  }
  printf("%zd", rng.get_iterations());
}

uint32_t RandomNumberGenerator::next() {
  ++iterations;
  number = 0x3FFFFFFF & (0x41C64E6D * number + 12345) % 0x80000000;
  return number;
}

size_t RandomNumberGenerator::get_iterations() const {
  return iterations;
}
