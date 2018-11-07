#include <cstdio>

struct ClockOfTheLongNow {
  void add_year() {
    year++;
  }
  int year;
};

int main() {
  ClockOfTheLongNow clock;
  clock.year = 2016;
  clock.add_year();
  printf("year: %d\n", clock.year);
  clock.add_year();
  printf("year: %d\n", clock.year);
}
