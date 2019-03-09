#include <iostream>
#include <iterator>

using namespace std;

int main() {
  ostreambuf_iterator<char> itr{ cout };
  *itr = 'H';
  ++itr;
  *itr = 'i';
}
