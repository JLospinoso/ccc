#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

// Listing 11-39
struct Stopwatch {
  explicit Stopwatch(chrono::nanoseconds& result)
      : result{ result }
      , start{ chrono::high_resolution_clock::now() } {}
  ~Stopwatch() {
    result = chrono::high_resolution_clock::now() - start;
  }

  private:
  chrono::nanoseconds& result;
  const chrono::time_point<chrono::high_resolution_clock> start;
};

vector<long> make_random_vector() {
  vector<long> numbers(1'000'000'000);
  iota(numbers.begin(), numbers.end(), 0);
  mt19937_64 urng{ 121216 };
  shuffle(numbers.begin(), numbers.end(), urng);
  return numbers;
}

int main() {
  cout << "Constructing random vectors...";
  auto numbers_a = make_random_vector();
  auto numbers_b{ numbers_a };
  chrono::nanoseconds time_to_sort;
  cout << " " << numbers_a.size() << " elements.\n";
  cout << "Sorting with execution::seq...";
  {
    Stopwatch stopwatch{ time_to_sort };
    sort(execution::seq, numbers_a.begin(), numbers_a.end());
  }
  cout << " took " << time_to_sort.count() / 1.0E9 << " sec.\n";

  cout << "Sorting with execution::par...";
  {
    Stopwatch stopwatch{ time_to_sort };
    sort(execution::par, numbers_b.begin(), numbers_b.end());
  }
  cout << " took " << time_to_sort.count() / 1.0E9 << " sec.\n";
}