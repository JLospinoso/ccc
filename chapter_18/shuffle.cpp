#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>

using namespace std;

int main() {
  const string population = "ABCD";
  const size_t n_samples{ 1'000'000 };
  mt19937_64 urbg;
  map<string, size_t> samples;
  cout << fixed << setprecision(1);
  for(size_t i{}; i < n_samples; i++) {
    string result{ population };
    shuffle(result.begin(), result.end(), urbg);
    samples[result]++;
  }
  for(const auto [sample, n] : samples) {
    const auto percentage = 100 * n / static_cast<double>(n_samples);
    cout << percentage << " '" << sample << "'\n";
  }
}
