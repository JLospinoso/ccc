#include <cstdio>

struct ConsoleLogger {
  void log_transfer(long from, long to, double amount) {
    printf("%ld -> %ld: %f\n", from, to, amount);
  }
};

struct Bank {
  void make_transfer(long from, long to, double amount) {
    //
    logger.log_transfer(from, to, amount);
  }
  ConsoleLogger logger;
};

int main() {
  Bank bank;
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
}
