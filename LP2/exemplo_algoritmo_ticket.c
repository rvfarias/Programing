#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int varGlobal;

int number = 1;
int next = 1;
int turn[5] = { 0, 0, 0, 0, 0 };

void* funcao(void* p) {
	long n = (long) p;
	printf("Thread #%ld - iniciando sua funcao...", n);
	while(1) {
		printf("Thread #%ld - dentro da iteracao", n);
		turn[n] = __sync_fetch_and_add(&number, 1);
		while(turn[n] != next);
		printf("Thread #%ld - dentro da secao critica\n", n);
		varGlobal++;
		printf("Thread #%ld - globalVar = %d - ticket %d\n", n, varGlobal, turn[n]);
		next++;

	}

}

int main(void) {

	pthread_t threads[5];


	varGlobal = 0;

	printf("(main) Antes de criar as threads.\n");

	long i;

	for (i = 0; i < 5; i++) {

		pthread_create(&threads[i], NULL, funcao, (void*) i);

	}
	printf("(main) threads criadas\n");

	sleep(10);

        while(varGlobal < 150);

        printf("varGlobal chegou em %d - finalizando...\n", varGlobal);

    return 0;

}
