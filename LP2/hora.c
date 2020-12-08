#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int main(int argc,char *argv[],char *envp[]){

  //ponteiro para struct que armazena data e hora
  struct tm *hora_atual;

  //variável do tipo time_t para armazenar o tempo em segundos
  time_t segundos;

  //obtendo o tempo em segundos
  time(&segundos);

  hora_atual = localtime(&segundos);

  printf("Hora ........: %d:",hora_atual->tm_hour);//hora
  printf("%d:",hora_atual->tm_min);//minuto
  printf("%d\n",hora_atual->tm_sec);//segundo

  return 0;
}
