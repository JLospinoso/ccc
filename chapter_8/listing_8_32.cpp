#include <cstdio>

int main() {
  goto silent_bob;
luke:
  printf("I'm not afraid.\n");
  goto yoda;
silent_bob:
  goto luke;
yoda:
  printf("You will be.");
}
