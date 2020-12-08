#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

//Struct para armazenar e passar todos parametros para as threads
typedef struct {
    long ind;
    double dist;

}tDados;

//Variavel global para verificação do vencedor
double tamanho = 160;

//Função de salto e verificação
void *funcao(void *d){
    tDados *dados = d;
    double percorrido;
    double salto;

    //Aplicando os saltos 
    while(1){
        salto = ((double)rand() * dados->dist)/ (double) RAND_MAX;

        percorrido += salto;
        printf("Distancia do salto efetuado da lebre: %lf\n",salto);
        printf("Distancia percorrida da lebre: %lf\n", percorrido);

        //Verificando vencedor
        if(percorrido >= tamanho){
            printf("Lebre [%ld] venceu! \n", dados->ind);
            exit(0);
        }

        sleep(1);
    }

}

int main(){

    //Array das threads
    pthread_t p[10];

    //Declarando as structs
    tDados dados1, dados2, dados3, dados4, dados5;
    tDados dados6, dados7, dados8, dados9, dados10;

    //Inicializando as structs e as threads
    dados1.ind = 0;
    dados1.dist = (rand() % 20) + 20;

    pthread_create(&p[0],NULL, funcao, &dados1);

    dados2.ind = 1;
    dados2.dist = (rand() % 20) + 20;
    pthread_create(&p[1],NULL, funcao, &dados2);

    dados3.ind = 2;
    dados3.dist = (rand() % 20) + 20;
    pthread_create(&p[2],NULL, funcao, &dados3);

    dados4.ind = 3;
    dados4.dist = (rand() % 20) + 20;
    pthread_create(&p[3],NULL, funcao, &dados4);

    dados5.ind = 4;
    dados5.dist = (rand() % 20) + 20;
    pthread_create(&p[4],NULL, funcao, &dados5);

    dados6.ind = 5;
    dados6.dist = (rand() % 20) + 20;
    pthread_create(&p[5],NULL, funcao, &dados6);

    dados7.ind = 6;
    dados7.dist = (rand() % 20) + 20;
    pthread_create(&p[6],NULL, funcao, &dados7);

    dados8.ind = 7;
    dados8.dist = (rand() % 20) + 20;
    pthread_create(&p[7],NULL, funcao, &dados8);

    dados9.ind = 8;
    dados9.dist = (rand() % 20) + 20;
    pthread_create(&p[8],NULL, funcao, &dados9);

    dados10.ind = 9;
    dados10.dist = (rand() % 20) + 20;
    pthread_create(&p[9],NULL, funcao, &dados10);

    //Chamada da função join
    pthread_join(p[0],NULL);

    pthread_join(p[1],NULL);

    pthread_join(p[2],NULL);

    pthread_join(p[3],NULL);

    pthread_join(p[4],NULL);

    pthread_join(p[5],NULL);

    pthread_join(p[6],NULL);

    pthread_join(p[7],NULL);

    pthread_join(p[8],NULL);

    pthread_join(p[9],NULL);

}
