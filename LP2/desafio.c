#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  int x, y;
  int pid_parent;
  int i;

  pid_parent = getpid();
  printf("Digite o numero de processos: ");
  scanf("%d", &x);
  printf("Digite o tempo de sleep: ");
  scanf("%d", &y);

  printf("Antes do fork apenas o processo original\n");
  sleep(5);

    if (getpid() == pid_parent) {

      for (i = 1; i < x; i++) {
        fork();
      }

    }else{

      exit(1);

    }

  sleep(y);


  return 0;
}
