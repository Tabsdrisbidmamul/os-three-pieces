#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int x = 100;
  int rc = fork();

  if(rc < 0) {
    fprintf(stderr, "failed to fork\n");
    exit(1);
  }

  if(rc == 0) {
    printf("before child (pid %d) x: %d\n", (int) getpid(), x);
    x = 110;
    printf("after child (pid %d) x: %d\n", (int) getpid(), x);
  } else {
    int wc = wait(NULL);
    printf("before parent (pid %d) x: %d\n", (int)getpid(), x);
    x = 200;
    printf("after parent (pid %d) x: %d\n", (int) getpid(), x);
  }

  return 0;
}