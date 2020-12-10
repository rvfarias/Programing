#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

//Declarando e inicializando variaveis
sem_t sem1, sem2;
float x, y, soma;

//Função de incremento
void* incremento(void* d) {

  long n = (long)d;
  float myrandom;

  srand(time(NULL));

	while(soma < 50) {

    //Identificando índice da thread
    if (n%2 == 0) {
      //Primeira thread par a chegar interfere na seção crítica o resto fica na espera
      sem_wait(&sem1);

      //Gera valor de incremento aleatório
      myrandom = (rand() % 10) + 0.5;
      if (myrandom > 10) {
        myrandom -= 0.5;
      }

      //Incrementando o valor de x
      x += myrandom;

      //Printando thread e valor gerado
      printf("----------------------\n");
      printf("Thread #%ld gerei %.2f\n", n, myrandom);

      //Atualizando soma
      soma  =  x + y;

      //Printando alteração
      printf("E mudei x para: %.2f\n", x);
      printf("----------------------\n");

      //Liberando seção crítica
      sem_post(&sem1);
      //Dormindo valor indicado
      usleep(250000);

    } else {
      //Primeira thread ímpar a chegar interfere na seção crítica o resto fica na espera
      sem_wait(&sem2);
      //Gera valor de incremento aleatório
      myrandom = (rand() % 5) + 2.5;
      //Incrementando o valor de y
      y += myrandom;

      //Printando thread e valor gerado
      printf("----------------------\n");
      printf("Thread #%ld gerei %.2f\n", n, myrandom);

      //Atualizando soma
      soma  =  x + y;

      //Printando alteração
      printf("E mudei y para: %.2f\n", y);
      printf("----------------------\n");

      //Gerando tempo aleatório entre 100ms e 300ms para função usleep
      int tempo = (rand() % 300000);
      if (tempo < 100000) {
        tempo += 100000;
      }

      //Liberando seção crítica
      sem_post(&sem2);
      //Dormindo tempo do valor gerado
      usleep(tempo);

    }

	}
  //Finalizando programa ao tingir limite da soma
  printf("Soma atingiu valor de: %.2f\nFinalizando programa...\n", soma);
  exit(0);

}


int main() {
    //Inicializando semáforo
	  sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 1);

    x = y = 0;
    //Declaração das threds
	  pthread_t threds[10];
    //Inicializando as threds
    for (long i = 0; i < 10; i++) {
      pthread_create(&threds[i], NULL, incremento, (void*)i);

    }

    while(1);

    return 0;
}
