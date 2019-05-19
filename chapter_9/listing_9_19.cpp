#include <cstdint>
#include <cstdio>

int main() {
  char to_count{ 's' };
  size_t tally{};
  auto s_counter = [to_count, &tally](const char* str) {
    size_t index{}, result{};
    while(str[index]) {
      if(str[index] == to_count)
        result++;
      index++;
    }
    tally += result;
    return result;
  };
  printf("Tally: %zd\n", tally);
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  printf("Tally: %zd\n", tally);
  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);
  printf("Tally: %zd\n", tally);
}
