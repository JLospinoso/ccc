#include <cstdio>
namespace BroopKidron13::Shaltanac {

enum class Color { Mauve, Pink, Russet };

struct JoopleberryShrub {
  const char* name;
  Color shade;
};

bool is_more_mauvey(const JoopleberryShrub& shrub) {
  return shrub.shade == Color::Mauve;
}
} // namespace BroopKidron13::Shaltanac

using namespace BroopKidron13::Shaltanac;
int main() {
  const JoopleberryShrub yours{ "The other Shaltanac", Color::Mauve };
  if(is_more_mauvey(yours)) {
    printf("%s's joopleberry shrub is always a more mauvey shade of pinky russet.", yours.name);
  }
}
