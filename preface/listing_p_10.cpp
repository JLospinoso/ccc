#include <cstdlib>

struct HolmesIV {
  bool is_sentient;
  int sense_of_humor_rating;
};

HolmesIV* make_mike(int sense_of_humor) {
  auto mike = (HolmesIV*)malloc(sizeof(HolmesIV));
  mike->is_sentient = true;
  mike->sense_of_humor_rating = sense_of_humor;
  return mike;
}

int main() {
  auto mike = make_mike(1000);
  free(mike);
}
