#include <stdlib.h>
#include <stdio.h>

void assert_iequals(const int expected, const int actual) {
  if (expected != actual) {
    printf("assertion failed:\n");
    printf("  expected: %i, actual: %i\n", expected, actual);
    exit(EXIT_FAILURE);
  }
}
