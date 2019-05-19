#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow() {
    year = 2019;
  }
  void add_year() {
    year++;
  }
  bool set_year(int new_year) {
    if(new_year < 2019)
      return false;
    year = new_year;
    return true;
  }
  int get_year() {
    return year;
  }

  private:
  int year;
};

int main() {
  ClockOfTheLongNow clock;
  printf("Default year: %d", clock.get_year());
}
