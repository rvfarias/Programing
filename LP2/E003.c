#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

//String que armazenará a palavra
char palavra[7];
//Declaração da barreira
pthread_barrier_t barreira;

void* gera_caractere(void* p) {

        //Declaração variaveis auxiliares
        long n = (long)p;
        int x;
        //Função de sincronização das threds
        pthread_barrier_wait(&barreira);
        //Gerando número aleatório entre 65 e 90
        srand(time(NULL));

        x = (rand() % 90);

        if (x < 26) {
                x+=65;
        }
        else if(x < 52) {
                x+=39;
        }
        else if(x < 65) {
                x+=13;
        }
        //Convertendo numero em caractere(de A a Z)
        palavra[n] = x;

        if (n == 5) {
                palavra[6] = '\0';
        }

        sleep(2);

}

int main(int argc, char const *argv[]) {

        //Variavel de controle das repetições
        int cont = 0;
        //Declaração variaveis auxiliares
        long i, j;
        char str1[4];
        char str2[4];
        pthread_attr_t att;
        //Declaração das threds
        pthread_t workers[6];
        //Inicializando a barreira
        pthread_barrier_init(&barreira, NULL, 6);

        //Loop para a geração de 10 palavras
        while (cont < 10) {

                //Limpando as strings
                palavra[0] = '\0';
                str1[0] = '\0';
                str2[0] = '\0';

                //Criando as threds
                for (i = 0; i < 6; i++) {

                        pthread_attr_init(&att);
                        pthread_create(&workers[i], NULL, gera_caractere, (void*)i);

                }
                //Aguardando cada thread gerar um caractere
                for (i = 0; i < 6; i++) {

                        pthread_join(workers[i], NULL);

                }

                //Dividindo a palavra para comparação
                int k = 5;
                for (j = 0; j < 3; j++) {

                        str1[j] = palavra[j];
                        str2[j] = palavra[k];
                        k--;

                }

                str1[3] = '\0';
                str2[3] = '\0';

                //Mostrando a palavra gerada
                printf("---------------------\n");
                printf("Palavra gerada: %s\n", palavra);

                //Verificando se a palavra gerada é um palíndromo
                if (!strcmp(str1, str2)) {

                        printf("Eh um palindromo\n");
                        printf("---------------------\n");

                }else{
                        printf("Nao eh um palindromo\n");
                        printf("---------------------\n");

                }

                cont++;
        }

        //Destruindo a barreira
        pthread_barrier_destroy(&barreira);

        return 0;

}
