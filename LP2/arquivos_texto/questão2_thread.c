#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct  {
  char str[11];
  FILE* fp;
}tDados;

int total = 0;

void* funcao1(void* d) {

        long x = 0;
        tDados *dados = d;
        char aux[11];

        printf("Lendo arquivo 1\n");
        while(fgets(aux, 11, dados->fp) != NULL){

          aux[strlen(aux)-1] = '\0';

          if(!strcmp(dados->str, aux)){
      	     x++;
          }
        }
        printf("%ld\n", x);
        total += x;
        return (void*)x;

}

void* funcao2(void* d) {

        long x = 0;
        tDados *dados = d;
        char aux[11];

        printf("Lendo arquivo 1\n");
        while(fgets(aux, 11, dados->fp) != NULL){

          aux[strlen(aux)-1] = '\0';

          if(!strcmp(dados->str, aux)){
      	     x++;
          }
        }
        printf("%ld\n", x);
        total += x;
        return (void*)x;

}

int main(int argc, char const *argv[]) {

                                                             //Variável do total de contagem
  tDados dados1;
  tDados dados2;

  dados1.fp = fopen("2.txt", "r");
  if(dados1.fp == NULL){
     printf("Erro!!");
  }

  dados2.fp = fopen("3.txt", "r");
  if(dados2.fp == NULL){
     printf("Erro!!");
  }
  //FILE *stream2;
  //FILE *stream3;
  //FILE *stream4;
  //FILE *stream5;

  pthread_t threadFuncao1;//, threadFuncao1, threadFuncao1, threadFuncao1, threadFuncao1;

  printf("Digite a sequencia de caracteres(max 10):");
  //Lendo a string a ser comparada
  fgets(dados1.str, 11, stdin);
  dados1.str[strlen(dados1.str)-1] = '\0';

  strcpy(dados2.str, dados1.str);

  pthread_create(&threadFuncao1, NULL, funcao1, &dados1);
  pthread_create(&threadFuncao1, NULL, funcao1, &dados2);
  pthread_join(threadFuncao1, NULL);

  printf("\nTotal de frequencias: %d\n", total);
  return 0;
}
