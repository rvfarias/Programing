#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//Variavel Global
double varGlobal = 8;

//Fução de verificação
void* funcao(void* x) {

        long aux = (long)x;

        printf("Thread %li:\n", aux+1);
        if (aux%2 == 0) {
          for (int i = 0; i < 10; i++) {
            varGlobal++;
            printf("%lf\n", varGlobal);
            sleep((rand() % 3) + 1);
          }

        }else{
          for (int i = 0; i < 10; i++){
              varGlobal--;
              printf("%lf\n", varGlobal);
              sleep((rand() % 3) + 1);
          }
        }

}


int main(int argc, char const *argv[]) {

  //Array com os identificadores
  long ind[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  //Declarando as threads
  pthread_t thread1, thread2, thread3, thread4, thread5;
  pthread_t thread6, thread7, thread8, thread9, thread10;

  //Criando as threads
  pthread_create(&thread1, NULL, funcao, (void*)ind[0]);

  pthread_create(&thread2, NULL, funcao, (void*)ind[1]);

  pthread_create(&thread3, NULL, funcao, (void*)ind[2]);

  pthread_create(&thread4, NULL, funcao, (void*)ind[3]);

  pthread_create(&thread5, NULL, funcao, (void*)ind[4]);

  pthread_create(&thread6, NULL, funcao, (void*)ind[5]);

  pthread_create(&thread7, NULL, funcao, (void*)ind[6]);

  pthread_create(&thread8, NULL, funcao, (void*)ind[7]);

  pthread_create(&thread9, NULL, funcao, (void*)ind[8]);

  pthread_create(&thread10, NULL, funcao, (void*)ind[9]);
  //Chamando a função join para a ultima thread para que as instruções exucutem o maximo possivel
  pthread_join(thread10, NULL);

  //Printando o valor final da variavel global
  printf("\nValor final de varGlobal: %lf\n", varGlobal);

  return 0;

}

/*
A concorrẽncia ocorre na programção, quando criamos um programa que realiza instruções paralelizadas ou entrlaçadas,
dependedo da arquitetura do coputador.

O sistema operacional faz a comunicação entre o processador e a memoria para a exucução das instuções de um programa,
e atráves dos escalonadores o sistema operacional organiza a execução dos processos concorrentes.

A consistência de memória se dá quando a exucução de dois programas(um sequencia e outro concorrente), possuem os
mesmos resultados, o que não ocorre no programa em questão já que o programa não aguarda
o termino de suas threads, fazendo com que haja perdas de dadas durante a execução.
*/
