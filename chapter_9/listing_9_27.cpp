#include <cstdint>
#include <cstdio>
#include <functional>

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

size_t count_spaces(const char* str) {
  size_t index{}, result{};
  while(str[index]) {
    if(str[index] == ' ')
      result++;
    index++;
  }
  return result;
}

std::function<size_t(const char*)> funcs[]{ count_spaces, CountIf{ 'e' }, [](const char* str) {
                                             size_t index{};
                                             while(str[index])
                                               index++;
                                             return index;
                                           } };

auto text = "Sailor went to sea to see what he could see.";

int main() {
  size_t index{};
  for(const auto& func : funcs) {
    printf("func #%zd: %zd\n", index++, func(text));
  }
}
