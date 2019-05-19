#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

struct Tracer {
  Tracer(std::string name_in)
      : name{ std::move(name_in) } {
    std::cout << name << " constructed.\n";
  }
  ~Tracer() {
    std::cout << name << " destructed.\n";
  }

  private:
  std::string name;
};

Tracer static_tracer{ "static Tracer" };

void run() {
  std::cout << "Registering a callback\n";
  std::at_quick_exit([] { std::cout << "***std::at_quick_exit callback executing***\n"; });
  std::cout << "Callback registered\n";
  std::quick_exit(0);
}

int main() {
  std::cout << "Entering main()\n";
  Tracer local_tracer{ "local Tracer" };
  thread_local Tracer thread_local_tracer{ "thread_local Tracer" };
  const auto* dynamic_tracer = new Tracer{ "dynamic Tracer" };
  run();
  delete dynamic_tracer;
  std::cout << "Exiting main()\n";
}