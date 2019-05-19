#include <cstdio>

namespace BroopKidron13::Shaltanac {
enum class Color { Mauve, Pink, Russet };
}

int main() {
  const auto shaltanac_grass = BroopKidron13::Shaltanac::Color::Russet;
  if(shaltanac_grass == BroopKidron13::Shaltanac::Color::Russet) {
    printf("The other Shaltanac's joopleberry shrub is always "
           "a more mauvey shade of pinky russet.");
  }
}
