#include <cstdint>
#include <cstdio>

struct CountIf {
  CountIf(char x)
      : x{ x } {}
  size_t operator()(const char* str) const {
    size_t index{}, result{};
    while(str[index]) {
      if(str[index] == x)
        result++;
      index++;
    }
    return result;
  }

  private:
  const char x;
};

int main() {
  CountIf s_counter{ 's' };
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);
  auto buffalo = CountIf{ 'f' }("Buffalo buffalo Buffalo buffalo "
                                "buffalo buffalo Buffalo buffalo.");
  printf("Buffalo: %zd\n", buffalo);
}
