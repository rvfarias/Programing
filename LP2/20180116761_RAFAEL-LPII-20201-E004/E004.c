#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

//Porta que será solicitada ao sistema
#define SERVER_PORT 9999
//Mensagem inicial do socket servidor
const char *msg = "BEMVINDO\n";
//Struct a ser passada para as threads com informções dos clientes
typedef struct {
        long id;                                                                //Variável que armazenará identificador do socket do cliente
        long clientfd;                                                          //Variável que armazenará o fd do socket do cliente
        char ipAddress[INET_ADDRSTRLEN];                                        //Variável que armazenará o ip do socket do cliente

}tDataClient;


void *verify_msg(void *d){
        //Declaração e inicialização de variáveis
        tDataClient *data = d;
        int finished = 0;                                                       //Variável de controle do loop
        char buf[12];                                                           //String que receberá a mensagem do socket do cliente
        //Strings auxiliares
        char str1[6];
        char str2[6];
        //Variáveis auxiliares
        int j, k, aux;

        //Iniciando comunicação com o cliente
        write(data->clientfd, msg, strlen(msg));
        //Mostrando ip do cliente
        printf("Ip do cliente #%ld: %s\n", data->id + 1, data->ipAddress);
        //Loop para a contínua recepção de mensagens
        while (!finished) {
                //Solicitando mensagem ao cliente
                bzero(buf,12);
                write(data->clientfd, "DIGITE SUA MENSAGEM(MAX 10 CARACTERES)\n", 40);
                read(data->clientfd, buf, 12);

                //Mostrando mensagem recebida do cliente
                printf("Recebi do cliente #%ld: %s\n", data->id + 1, buf);

                //Verifica se a string digitada é a palavra chave de finalização da comunicação
                if (strstr(buf, "BYEBYE") != NULL) {

                        finished = 1;
                }

                //Verifica se a string digitada é a palavra chave de finalização do servidor
                if (strstr(buf, "SHUTDOWN") != NULL) {
                        exit(0);
                }

                //Ajustando string para melhor verificação
                if (strlen(buf) > 0) {
                        buf[strlen(buf) -1] = '\0';

                                //Limpando as strings auxiliares
                                str1[0] = '\0';
                                str2[0] = '\0';
                                aux = strlen(buf) - 1;

                                for (int i = 0; i < aux; i++) {
                                        buf[i] = toupper(buf[i]);
                                }
                                //Dividindo a palavra para comparação
                                k = aux - 1;
                                for (j = 0; j < aux/2; j++) {

                                        str1[j] = buf[j];
                                        str2[j] = buf[k];
                                        k--;

                                }

                                str1[strlen(str1)] = '\0';
                                str2[strlen(str2)] = '\0';

                                //Verificando se a mensagem é um palíndromo
                                if (!strcmp(str1, str2)) {
                                        //Mostrando resultado ao cliente
                                        write(data->clientfd, "PALINDROMO=TRUE\n", 16);

                                }else{
                                        //Mostrando resultado ao cliente
                                        write(data->clientfd, "PALINDROMO=FALSE\n", 17);

                                }


                }


        }

        //Encerrando a conexao do cliente
        printf("Cliente #%ld desconectou!!!\n", data->id + 1);
        close(data->clientfd);
        pthread_exit(0);

}

int main(void){
        //Declaração e inicialização de variáveis
        pthread_t thread_client[6];
        tDataClient client[6];
        int serverfd;
        int i = 0;

        struct sockaddr_in serveraddr, cliaddr;

        unsigned sizecliaddr = sizeof(struct sockaddr);

        serverfd = socket(AF_INET, SOCK_STREAM, 0);
        //Testando criação do socket
        if (serverfd == -1) {

                printf("server socket creation error");
                exit(0);
        }

        bzero(&serveraddr, sizeof(serveraddr));

        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
        serveraddr.sin_port = htons(SERVER_PORT);

        //Verificando disponibilidade da porta para conexão
        if (bind(serverfd, ((struct sockaddr *)&serveraddr), sizeof(serveraddr)) != 0) {

                printf("Server socket bind error");
                exit(0);
        }
        //Verificando se a porta foi reservada pelo sistema operacional
        if (listen(serverfd, 4) != 0) {

                printf("Server socket listen error");
                exit(0);
        }
        //Mostrando porta reservada pelo sistema
        printf("Server socket listening on port: %d\n", SERVER_PORT);

        while (1) {
                //Iniciando conexão
                client[i].clientfd = accept(serverfd, ((struct sockaddr *)&cliaddr), &sizecliaddr);
                client[i].id = i;
                printf("Recebi conexao!\n");
                //Armazenando ip do cliente
                inet_ntop(AF_INET, &cliaddr.sin_addr, client[i].ipAddress, INET_ADDRSTRLEN);
                //Passando comunicação de cada cliente a uma thread
                pthread_create(&thread_client[i], NULL, verify_msg, &client[i]);
                //Incrementando variável que irá ser passada ao identificador
                i++;
        }

        printf("Encerrando servidor...\n");
}
