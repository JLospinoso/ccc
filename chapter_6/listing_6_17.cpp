template <typename T>
T square(T value) {
  return value * value;
}

int main() {
  char my_char{ 'Q' };
  //auto result = square(&my_char); // Bang!
}
