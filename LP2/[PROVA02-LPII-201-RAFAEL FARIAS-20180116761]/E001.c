/*
O código abaixo foi implementado com uso semáforos, para obter melhor controle sobre
as operações.Caso não houvesse tal recurso seria utilizado o meio deno,imado de espera
ocupada, que faz uso de travas e barreiras por meio de loops, o que demanda grandes
quantidades de recursos de hardware.
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

//Declarando e inicializando variaveis
sem_t mutex, limit;
float temp = 600;                                                               //Variável que armazena a temperatura
int cont = 0;                                                                   //Variável de controle de repetições

//Função de incremento da temperatura
void* change_temp(void* d) {

	printf("Aquecimento inicializado...\n");

	while(1) {
    srand(time(NULL));
    //Gera valor de incremento aleatório e soma a temperatura
		int myrandom = (rand() % 40) - 10;
		temp += myrandom;
    //Verificação para melhor apresentação
    if (myrandom >= 0) {
  		printf("----------------\nAqueceu mais %d graus\nNova temperatura: %.2f graus\n----------------", myrandom, temp);

    } else {

      printf("----------------\nEsfriou %d graus\nNova temperatura: %.2f graus\n----------------", myrandom, temp);

    }
    //Verificando se a temperatura chegou ou passou do limite
    if (temp >= 1000) {
      //Se passou libera a função de resfriamento
  		sem_post(&limit);
      //E trava os incrementos
      sem_wait(&mutex);
    }
    //Se não dá uma pausa e depois segue incrementando
    usleep(300000);

	}


}

//Função de decremento da temperatura
void* back_temp(void* d) {

  //Enquanto não resfriar 5 vezes o programa ficará executando
	while(cont < 5) {
    //Função ficará presa aqui, enquanto a temperatura não atingir o limite
		sem_wait(&limit);
    //Ao atingir o limite muda o valor da temperatura para o valor inicial
		temp = 600;
    //Incrementa variável de controle das repetições
    cont++;
		printf("----------------\nResfriando...\nTemperatura de volta aos %f graus\n----------------", temp);
    //Libera a função de aquecimento
    sem_post(&mutex);

	}
}


int main() {
    //Inicializando semaforos
	  sem_init(&mutex, 0, 0);
	  sem_init(&limit, 0, 0);
    //Declaração das threds
	  pthread_t change;
	  pthread_t back;
    //Inicializando as threds
    pthread_create(&change, NULL, change_temp, NULL);
    pthread_create(&back, NULL, back_temp, NULL);

	  pthread_join(back, NULL);

	return 0;
}
