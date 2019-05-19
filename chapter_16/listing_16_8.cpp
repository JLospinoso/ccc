#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  cout << "Gotham needs its " << boolalpha << true << " hero.";
  cout << "\nMark it " << noboolalpha << false << "!";
  cout << "\nThere are " << 69 << "," << oct << 105 << " leaves in here.";
  cout << "\nYabba " << hex << 3669732608 << "!";
  cout << "\nAvogadro's Number: " << scientific << 6.0221415e-23;
  cout << "\nHogwart's Platform: " << fixed << setprecision(2) << 9.750123;
  cout << "\nAlways eliminate " << 3735929054;
  cout << setw(4) << "\n" << 0x1 << "\n" << 0x10 << "\n" << 0x100 << "\n" << 0x1000 << endl;
}
