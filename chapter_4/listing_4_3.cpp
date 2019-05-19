#include <cstdio>

void power_up_rat_thing(int nuclear_isotopes) {
  static int rat_things_power = 200;
  rat_things_power = rat_things_power + nuclear_isotopes;
  const auto waste_heat = rat_things_power * 20;
  if(waste_heat > 10000) {
    printf("Warning! Hot doggie!\n");
  }
  printf("Rat-thing power: %d\n", rat_things_power);
}

int main() {
  power_up_rat_thing(100);
  power_up_rat_thing(500);
  return 0;
}
