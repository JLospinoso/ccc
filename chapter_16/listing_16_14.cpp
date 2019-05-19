#include <fstream>

using namespace std;

int main() {
  ofstream file{ "lunchtime.txt", ios::out | ios::app };
  file << "Time is an illusion." << endl;
  file << "Lunch time, " << 2 << "x so." << endl;
}