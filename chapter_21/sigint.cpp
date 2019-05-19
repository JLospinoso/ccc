#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <thread>

std::atomic_bool interrupted{};

extern "C" void handler(int signal) {
  std::cout << "Handler invoked with signal " << signal << ".\n";
  interrupted = true;
}

int main() {
  using namespace std::chrono_literals;
  std::signal(SIGINT, handler);
  while(!interrupted) {
    std::cout << "Waiting..." << std::endl;
    std::this_thread::sleep_for(1s);
  }
  std::cout << "Interrupted!\n";
}