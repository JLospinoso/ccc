#include <future>
#include <iostream>
#include <mutex>

using namespace std;

void goat_rodeo() {
  const size_t iterations{ 1'000'000 };
  int tin_cans_available{};
  mutex tin_can_mutex;
  auto eat_cans = async(launch::async, [&] {
    for(size_t i{}; i < iterations; i++) {
      lock_guard<mutex> guard{ tin_can_mutex };
      tin_cans_available--;
    }
  });
  auto deposit_cans = async(launch::async, [&] {
    for(size_t i{}; i < iterations; i++) {
      lock_guard<mutex> guard{ tin_can_mutex };
      tin_cans_available++;
    }
  });
  eat_cans.get();
  deposit_cans.get();
  cout << "Tin cans: " << tin_cans_available << "\n";
}

int main() {
  goat_rodeo();
  goat_rodeo();
  goat_rodeo();
}
