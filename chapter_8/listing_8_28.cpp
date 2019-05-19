#include <cstdio>

struct FibonacciIterator {
  bool operator!=(int x) const {
    return x >= current;
  }

  FibonacciIterator& operator++() {
    const auto tmp = current;
    current += last;
    last = tmp;
    return *this;
  }

  int operator*() const {
    return current;
  }

  private:
  int current{ 1 }, last{ 1 };
};

struct FibonacciRange {
  explicit FibonacciRange(int max)
      : max{ max } {}
  FibonacciIterator begin() const {
    return FibonacciIterator{};
  }
  int end() const {
    return max;
  }

  private:
  const int max;
};

int main() {
  FibonacciRange range{ 5000 };
  const auto end = range.end();
  for(auto x = range.begin(); x != end; ++x) {
    const auto i = *x;
    printf("%d ", i);
  }
}
