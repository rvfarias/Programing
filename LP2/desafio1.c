#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {

  int x, y;
  int pid_r;
  int i;

  printf("Digite o numero de processos: ");
  scanf("%d", &x);
  printf("Digite o tempo de sleep: ");
  scanf("%d", &y);

  printf("Antes do fork apenas o processo original\n");
  sleep(5);

  if (x > 0) {
    pid_r = fork();

    if (pid_r == 0) {

      for (i = 1; i < x; i++) {
        fork();
      }
      printf("Processo clonado aqui\n");

    }else{
      printf("Processo original aqui\n");

    }

  }
  sleep(y);


  return 0;
}
