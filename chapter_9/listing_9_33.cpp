#include <cstdint>
#include <cstdio>

constexpr char pos_A{ 65 }, pos_Z{ 90 }, pos_a{ 97 }, pos_z{ 122 };
constexpr bool within_AZ(char x) {
  return pos_A <= x && pos_Z >= x;
}
constexpr bool within_az(char x) {
  return pos_a <= x && pos_z >= x;
}

struct AlphaHistogram {
  void ingest(const char* x);
  void print() const;

  private:
  size_t counts[26]{};
};

void AlphaHistogram::ingest(const char* x) {
  size_t index{};
  while(const auto c = x[index]) {
    if(within_AZ(c))
      counts[c - pos_A]++;
    else if(within_az(c))
      counts[c - pos_a]++;
    index++;
  }
}

void AlphaHistogram::print() const {
  for(auto index{ pos_A }; index <= pos_Z; index++) {
    printf("%c: ", index);
    auto n_asterisks = counts[index - pos_A];
    while(n_asterisks--)
      printf("*");
    printf("\n");
  }
}

int main(int argc, char** argv) {
  AlphaHistogram hist;
  for(size_t i{ 1 }; i < argc; i++) {
    hist.ingest(argv[i]);
  }
  hist.print();
}
