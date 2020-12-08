#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int copy1, copy2, copy3, copy4, copy5;                                        //Variáveis que chamarão os forks
  int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;                    //Variáveis de contagem
  int total = 0;                                                                //Variável do total de contagem
  char str1[11], str2[11];
  FILE *stream;

    printf("Digite a sequencia de caracteres(max 10):");
    //Lendo a string a ser comparada
    fgets(str1, 11, stdin);
    str1[strlen(str1)-1] = '\0';

    //Criando processo filho
    copy1 = fork();

    //Verificando se houve sucesso no fork
    if (copy1 >= 0) {

        if (copy1 == 0) {
          //Abrindo o primeiro arquivo
          stream = fopen("0.txt", "r");
          if(stream == NULL){
             printf("Erro!!");
          }

          //Lendo o arquivo 1 e comparando com a string obtida
          printf("Lendo arquivo 1...\n");
          while(fgets(str2, 11, stream) != NULL){

            str2[strlen(str2)-1] = '\0';

            if(!strcmp(str1, str2)){
               cont1++;
            }
          }

            //Criando processo neto
            copy2 = fork();

            if (copy2 == 0) {

              //Abrindo segundo arquivo
              stream = fopen("1.txt", "r");
              if(stream == NULL){
                 printf("Erro!!");
              }

              //Lendo o arquivo 2 e comparando com a string obtida
              printf("Lendo arquivo 2...\n");
              while(fgets(str2, 11, stream) != NULL){

                str2[strlen(str2)-1] = '\0';

                if(!strcmp(str1, str2)){
                   cont2++;
                }
              }

                //Criando processo bisneto
                  copy3 = fork();

                  if (copy3 == 0) {

                    //Abrindo terceiro arquivo
                    stream = fopen("2.txt", "r");

                    if(stream == NULL){
                       printf("Erro!!");
                    }

                    //Lendo o arquivo 3 e comparando com a string obtida
                    printf("Lendo arquivo 3...\n");
                    while(fgets(str2, 11, stream) != NULL){

                      str2[strlen(str2)-1] = '\0';

                      if(!strcmp(str1, str2)){
                         cont3++;
                      }
                    }

                    //Criando processo tataraneto
                      copy4 = fork();

                      if (copy4 == 0) {

                        //Abrindo quarto arquivo
                        stream = fopen("3.txt", "r");

                        if(stream == NULL){
                           printf("Erro!!");
                        }

                        //Lendo o arquivo 4 e comparando com a string obtida
                        printf("Lendo arquivo 4...\n");
                        while(fgets(str2, 11, stream) != NULL){

                          str2[strlen(str2)-1] = '\0';

                          if(!strcmp(str1, str2)){
                             cont4++;
                          }
                        }

                        //Criando processo tataratataraneto
                        copy5 = fork();

                        if (copy5 == 0) {

                          //Abrindo quinto arquivo
                          stream = fopen("4.txt", "r");

                          //Lendo o arquivo 5 e comparando com a string obtida
                          printf("Lendo arquivo 5...\n");
                          while(fgets(str2, 11, stream) != NULL){

                            str2[strlen(str2)-1] = '\0';

                            if(!strcmp(str1, str2)){
                               cont5++;
                            }
                          }

                          //Processo tataratataraneto encerrando e retornando o valor da contagem
                          fclose(stream);
                          printf("\nNumero de frequencias no arquivo 5: %d", cont5);
                          exit(cont5);

                        } else {
                          //Processo tataraneto aguardando a contagem do processo tataratataraneto
                          fclose(stream);
                          wait(&total);
                          //Processo tataraneto encerrando e retornando o valor da contagem
                          printf("\nNumero de frequencias no arquivo 4: %d", cont4);
                          exit(cont4+WEXITSTATUS(total));
                        }


                      } else {
                        //Processo bisneto aguardando a contagem do processo tataraneto
                        fclose(stream);
                        wait(&total);
                        //Processo bisneto encerrando e retornando o valor da contagem
                        printf("\nNumero de frequencias no arquivo 3: %d", cont3);
                        exit(cont3+WEXITSTATUS(total));
                      }
                  } else {
                    //Processo neto aguardando a contagem do processo bisneto
                    fclose(stream);
                    wait(&total);
                    //Processo neto encerrando e retornando o valor da contagem
                    printf("\nNumero de frequencias no arquivo 2: %d", cont2);
                    exit(cont2+WEXITSTATUS(total));
                  }

            } else {
              //Processo filho aguardando a contagem do processo neto
              fclose(stream);
              wait(&total);
              //Processo filho encerrando e retornando o valor da contagem
              printf("\nNumero de frequencias no arquivo 1: %d", cont1);
              exit(cont1 + WEXITSTATUS(total));
            }

      } else {
        //Processo original aguardando a contagem do processo filho
        wait(&total);
        printf("\n");
        printf("\nNumero de frequencias total: %d\n", WEXITSTATUS(total));
        exit(0);
      }

    }else{ //Caso haja error na chamada do fork
      perror("Error no fork");
    }
}
