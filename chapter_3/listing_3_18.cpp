#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow(int year_in) {
    if(!set_year(year_in)) {
      year = 2019;
    }
  }
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
  int get_year() const {
    return year;
  }

  private:
  int year;
};

struct Avout {
  Avout(const char* name, int year_of_apert)
      : name{ name }
      , apert{ year_of_apert } {}
  void announce() const {
    printf("My name is %s and my next apert is %d.\n", name, apert.get_year());
  }
  const char* name;
  ClockOfTheLongNow apert;
};

int main() {
  Avout raz{ "Erasmas", 3010 };
  Avout jad{ "Jad", 4000 };
  raz.announce();
  jad.announce();
}
