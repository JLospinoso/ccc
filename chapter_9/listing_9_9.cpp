#include <cstdio>
#include <stdexcept>

template <typename To, typename From>
struct NarrowCaster {
  To cast(From value) {
    auto converted = static_cast<To>(value);
    auto backwards = static_cast<From>(converted);
    if (value != backwards) throw std::runtime_error("Narrowed!");
    return converted;
  }
};

template <typename From>
using short_caster = NarrowCaster<short, From>;

int main() {
  try {
    short_caster<int> caster;
    auto cyclic_short = caster.cast(142857);
    printf("cyclic_short: %d\n", cyclic_short);
  } catch (const std::runtime_error& e) {
    printf("Exception: %s\n", e.what());
  }
}
