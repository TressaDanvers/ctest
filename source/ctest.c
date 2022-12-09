#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include <sys/wait.h>
#include <unistd.h>

#define VERSION "0.0.0.1"

int main(const unsigned char argc, const char *args[]) {
  if (argc == 2) {
    if (strcmp(args[1], "--version") == 0 ||
        strcmp(args[1], "-v") == 0) {
      printf("ctest version: %s\n", VERSION);
      exit(EXIT_SUCCESS);
    } else {
      printf("unknown argument: %s\n", args[1]);
      exit(EXIT_FAILURE);
    }
  } else if (argc == 3) {
    if (strcmp(args[1], "--bin") == 0 ||
        strcmp(args[1], "-b") == 0) {
      pid_t pid = fork();
      if (pid == 0) {
        if (access(args[2], F_OK) == 0) {
          char *exec_args[] = { NULL };
          execvp(args[2], exec_args);
        } else {
          printf("unknown argument: %s\n", args[2]);
          exit(EXIT_FAILURE);
        }
      } else {
        int exit_status;
        wait(&exit_status);
        if (exit_status == 0)
          printf("test passed\n");
        else
          printf("test failed with error code: %i\n", exit_status);
      }
      exit(EXIT_SUCCESS);
    } else {
      printf("unknown argument: %s\n", args[1]);
      exit(EXIT_FAILURE);
    }
  } else {
    printf("invalid arguments\n");
    exit(EXIT_FAILURE);
  }
}
