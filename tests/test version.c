#include <stdlib.h>
#include <stdio.h>

#include <sys/wait.h>
#include <unistd.h>

#include <assertions.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    char *args[] = { "./build/ctest", "--version", NULL };
    execvp("./build/ctest", args);
  } else {
    int exit_status;
    wait(&exit_status);
    assert_iequals(0, exit_status);
  }

  exit(EXIT_SUCCESS);
}
