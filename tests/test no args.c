#include <stdlib.h>

#include <sys/wait.h>
#include <unistd.h>

#include "../source/assertions.c"

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    char *args[] = { NULL };
    execvp("ctest", args);
  } else {
    int exit_status;
    wait(&exit_status);
    assert_iequals(256, exit_status);
  }
}
