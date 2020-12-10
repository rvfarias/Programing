#include<stdio.h>
#include<unistd.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

#define SERVER_PORT 9999

int main(void){

    //Declaração de variaveis
    int client;                                                                 //Variável que armazenará fd do socket do cliente
    int cont = 6;                                                               //Variável de controle de repetições
    int x;                                                                      //Variável auxiliar para a formação da string
    char buf[21];                                                               //String que receberá mensagem do servirdor
    char palavra[7];                                                            //String que armazenará palavra formada

    struct sockaddr_in servaddr;
    //Inicializando servidor cliente
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client == -1){
        printf("client socket creation error");
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(SERVER_PORT);


    bind(client, ((struct sockaddr *)&servaddr), sizeof(servaddr));

    int conex = connect(client, (struct sockaddr *)&servaddr, sizeof(servaddr));

    //Testando conexao
    if (conex != 0){
        printf("Connection error!");
        exit(0);
    }

    printf("Client connected to port %d\n", SERVER_PORT);

    //Loop para envio das strings
    while (cont){

        bzero(buf, 20);
        //Recebendo mensagem do servidor
        read(client, buf, 20);

        if (strlen(buf) > 0){
          buf[strlen(buf) - 1] = '\0';
          printf("Recebi do servidor: %s\n", buf);

        }

        //Gerando número aleatório entre 65 e 90
        srand(time(NULL));
        for (int i = 0; i < 6; i++) {
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
          palavra[i] = x;
          if (i == 5) {
                  palavra[6] = '\0';
          }
        }

        //Enviando palavra gerada para o servidor
        printf("Vou enviar: %s\n", palavra);
        palavra[6] = '\n';
        write(client, palavra, strlen(palavra));

        sleep(1);

        cont--;
    }
}
/*
Para o funcionamento do protocolo TCP é necessário criar o socket e associar os
parâmetros através da função bind(), depois a função listened() avisará o sistema
operacional que estou criando um sever socket para ele reservar uma porta, e então
invocar a função bloqueante accept() que só desbloqueará quando chegar um cliente,
que criará outro socket que realizará a comunicação de um cliente especifico para
então fazer uso das funções read() e write().Já o socket cliente a patir da conexão
com o sever realizará as funções de comunicação.
*/
