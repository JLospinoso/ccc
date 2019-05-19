template <typename T>
T add(T x, T y, T z) {
  return x + y + z;
}

int main() {
  auto a = add(1, 2, 3); // a is an int
  auto b = add(1L, 2L, 3L); // b is a long
  auto c = add(1.F, 2.F, 3.F); // c is a float
}
