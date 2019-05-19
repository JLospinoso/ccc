#include <iostream>
#include <string>

using namespace std;

int main() {
  double x, y;
  cout << "X: ";
  cin >> x;
  cout << "Y: ";
  cin >> y;

  string op;
  cout << "Operation: ";
  cin >> op;
  if(op == "+") {
    cout << x + y;
  } else if(op == "-") {
    cout << x - y;
  } else if(op == "*") {
    cout << x * y;
  } else if(op == "/") {
    cout << x / y;
  } else {
    cout << "Unknown operation " << op;
  }
}