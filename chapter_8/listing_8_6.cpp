#include <cstdio>

namespace BroopKidron13::Shaltanac {
enum class Color { Mauve, Pink, Russet };
}

int main() {
  using BroopKidron13::Shaltanac::Color;
  const auto shaltanac_grass = Color::Russet;
  if(shaltanac_grass == Color::Russet) {
    printf("The other Shaltanac's joopleberry shrub is always "
           "a more mauvey shade of pinky russet.");
  }
}
