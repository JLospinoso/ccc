#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

int main() {
  ifstream file{ "numbers.txt" };
  auto maximum = numeric_limits<int>::min();
  int value;
  while(file >> value)
    maximum = maximum < value ? value : maximum;
  cout << "Maximum found was " << maximum << endl;
}
