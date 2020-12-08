#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  int x;
  int pid_r;

  x = 10;

  //scanf("%d", &x);
  printf("Antes do fork - x = %d\n", x);
  sleep(10);
  /*fork();
  printf("depois do primeiro fork\n");
  fork();
  printf("depois do segundo fork\n");
  fork();
  printf("depois do terceiro fork\n");
  fork();*/
  pid_r = fork();

  printf("Result of pid: %d\n", pid_r);
  if (pid_r == 0) {
    x = 1000;
    sleep(10);
    //while (1) {
      //printf("loop\n");
  //  }
    printf("Hello world! - x = %d\n", x);
  } else {
    x = 2000;
    printf("Hello world! - x = %d\n", x);
    sleep(10);
    //exit(0);
  }
  //printf("Depois do fork\n");

}
