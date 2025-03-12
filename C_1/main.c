#include <stdio.h>
int main() {
  int i_value = 16777217;
  float f_value = 16777216.0;
  printf("The integer is: %d\n", i_value);
  printf("The float is:   %f\n", f_value);
  printf("Their equality: %d\n", i_value == f_value);
  // NOTE: this should throw true equality hence the intuitive behaviour has
  // been
}
