#include <cstdint>
#include <cstdio>

template <typename Fn, typename T>
void transform(Fn fn, const T* in, T* out, size_t len) {
  for(size_t i{}; i < len; i++) {
    out[i] = fn(in[i]);
  }
}

int main() {
  constexpr size_t l{ 3 };
  int base_int[]{ 1, 2, 3 }, a[l];
  float base_float[]{ 10.f, 20.f, 30.f }, b[l];
  auto translate = [](auto x) { return 10 * x + 5; };
  transform(translate, base_int, a, l);
  transform(translate, base_float, b, l);

  for(size_t i{}; i < l; i++) {
    printf("Element %zd: %d %f\n", i, a[i], b[i]);
  }
}
