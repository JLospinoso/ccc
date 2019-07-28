#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>

using namespace std;

const string population = "ABCD";
const size_t n_samples{ 1'000'000 };
mt19937_64 urbg;

void sample_length(size_t n) {
  cout << "-- Length " << n << " --\n";
  map<string, size_t> counts;
  for(size_t i{}; i < n_samples; i++) {
    string result;
    sample(population.begin(), population.end(), back_inserter(result), n, urbg);
    counts[result]++;
  }
  for(const auto& [sample, count] : counts) {
    const auto percentage = 100 * count / static_cast<double>(n_samples);
    cout << percentage << " '" << sample << "'\n";
  }
}

int main() {
  cout << fixed << setprecision(1);
  sample_length(0);
  sample_length(1);
  sample_length(2);
  sample_length(3);
  sample_length(4);
}
