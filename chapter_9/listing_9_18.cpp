#include <cstdint>
#include <cstdio>

int main() {
  char to_count{ 's' };
  auto s_counter = [to_count](const char* str) {
    size_t index{}, result{};
    while(str[index]) {
      if(str[index] == to_count)
        result++;
      index++;
    }
    return result;
  };
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);
}
