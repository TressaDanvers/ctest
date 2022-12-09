#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#define VERSION "0.0.0.0"

int main(const unsigned char argc, const char *args[]) {
  if (argc == 2) {
    if (strcmp(args[1], "--version") == 0 ||
        strcmp(args[1], "-v") == 0) {
      printf("ctest version: %s\n", VERSION);
      exit(EXIT_SUCCESS);
    } else {
      printf("unknown argument: %s\n");
      exit(EXIT_FAILURE);
    }
  } else {
    printf("invalid arguments\n");
    exit(EXIT_FAILURE);
  }
}
