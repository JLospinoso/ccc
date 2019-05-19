#include <cstdio>
#include <stdexcept>

template <typename To, typename From>
To narrow_cast(From value) {
  const auto converted = static_cast<To>(value);
  const auto backwards = static_cast<From>(converted);
  if(value != backwards)
    throw std::runtime_error{ "Narrowed!" };
  return converted;
}

int main() {
  int perfect{ 496 };
  const auto perfect_short = narrow_cast<short>(perfect);
  printf("perfect_short: %d\n", perfect_short);
  try {
    int cyclic{ 142857 };
    const auto cyclic_short = narrow_cast<short>(cyclic);
    printf("cyclic_short: %d\n", cyclic_short);
  } catch(const std::runtime_error& e) {
    printf("Exception: %s\n", e.what());
  }
}
