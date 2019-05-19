#include <deque>
#include <iostream>

using namespace std;

template <typename T>
istream& operator>>(istream& s, deque<T>& t) {
  T element;
  while(s >> element)
    t.emplace_back(move(element));
  return s;
}

int main() {
  cout << "Give me numbers: ";
  deque<int> numbers;
  cin >> numbers;
  int sum{};
  cout << "Cumulative sum:\n";
  for(const auto& element : numbers) {
    sum += element;
    cout << sum << "\n";
  }
}