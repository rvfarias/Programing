#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long varGlobal = 0;

void* funcao1(void* x) {
        long myX = (long)x;
        printf("funcao1: recebi o valor %li\n", myX);
        long y;
        printf("Digite o valor de y: ");
        scanf("%li", &y);

        varGlobal = myX + y;

        printf("funcao1 varGlobal: %li\n", varGlobal);

        return (void*)y;

}

void* funcao2(void* d) {
        int contador = 0;
        while(varGlobal == 0);
        printf("funcao2: varGlobal mudou para %li\n", varGlobal);
        while(contador < 10) {
                printf("funcao2: contador %d\n", contador);
                contador++;
                sleep(1);
        }
}


int main(int argc, char const *argv[]) {

        pthread_t threadFuncao1, threadFuncao2;
        long valorMain = 100;

        printf("hello world - vou passar %li para funcao1\n", valorMain);

        pthread_create(&threadFuncao2, NULL, funcao2, NULL);
        pthread_create(&threadFuncao1, NULL, funcao1, (void*)valorMain);

        printf("antes do loop de main()\n");

        while(varGlobal == 0);

        printf("main: vou chamar o join para funcao2()\n");

        pthread_join(threadFuncao2, NULL);

        printf("main: exiting...\n");


        return 0;
}
