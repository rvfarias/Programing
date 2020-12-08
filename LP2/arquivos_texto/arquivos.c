#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (){

    char palavra[11], verificador[11];
    int t0, t1, t2, t3, t4; // VARIÁVEIS DE PROCESSOS.
    int oc0=0, oc1=0, oc2=0, oc3=0, oc4=0; //CONTADOR DE OCORRÊNCIAS DA PALAVRA POR CADA ARQUIVO.
    int N_freq = 0; // VARIÁVEL DO TOTAL DE OCORRÊNCIAS DA PALAVRA NOS 5 ARQUIVOS. (SERÁ RETORNO NO exit())
    FILE *arq;

    printf("Insira a palavra que busca: ");
    fgets(palavra, 11, stdin);
    if(palavra[strlen(palavra-1)] == '\n')
        palavra[strlen(palavra-1)] = '\0';

    t0 = fork();
    if(t0>=0){
        if(t0==0){
            arq = fopen("0.txt", "r");
            if(!arq){
                printf("Erro arquivo 0.\n");
                return 0;
            }

            while(fgets(verificador,11,arq) != NULL){

                if(verificador[strlen(verificador-1)] == '\n')
                    verificador[strlen(verificador-1)] = '\0';

                if(!strcmp(palavra, verificador))
                    oc0++;

            }

            t1 = fork();
            if(t1>=0){
                if(t1==0){
                    arq = fopen("1.txt", "r");
                    if(!arq){
                        printf("Arquivo 1 não abriu.");
                        return 0;
                    }

                    while(fgets(verificador,11,arq) != NULL){

                        if(verificador[strlen(verificador-1)] == '\n')
                            verificador[strlen(verificador-1)] = '\0';

                        if(!strcmp(verificador,palavra))
                          oc1++;

                    }

                    t2 = fork();
                    if(t2>=0){
                        if(t2==0){
                            arq = fopen("2.txt", "r");
                            if(!arq){
                                printf("Arquivo 2 não abriu.");
                                return 0;
                            }

                            while(fgets(verificador,11,arq) != NULL){

                                if(verificador[strlen(verificador-1)] == '\n')
                                    verificador[strlen(verificador-1)] = '\0';

                                if(!strcmp(verificador,palavra))
                                    oc2++;
                            }

                            t3 = fork();
                            if(t3>=0){
                                if(t3==0){
                                    arq = fopen("3.txt", "r");
                                    if(!arq){
                                        printf("Arquivo 3 não abriu.");
                                        return 0;
                                    }

                                    while(fgets(verificador,11,arq) != NULL){

                                        if(verificador[strlen(verificador-1)] == '\n')
                                            verificador[strlen(verificador-1)] = '\0';

                                        if(!strcmp(verificador,palavra))
                                            oc3++;
                                    }

                                    t4 = fork();
                                    if(t4>=0){
                                        if(t4==0){
                                            arq = fopen("4.txt", "r");
                                            if(!arq){
                                                printf("Arquivo 4 não abriu.");
                                                return 0;
                                            }

                                            while(fgets(verificador,11,arq) != NULL){

                                                if(verificador[strlen(verificador-1)] == '\n')
                                                    verificador[strlen(verificador-1)] = '\0';

                                                if(!strcmp(verificador,palavra))
                                                    oc4++;
                                            }

                                            fclose(arq);
                                            exit(oc4);

                                        }else if(t4>0){
                                            fclose(arq);
                                            wait(&N_freq);
                                            printf("Número de ocorrências no arquivo 4.txt: %d \n", oc4);
                                            exit(oc4 + WEXITSTATUS(N_freq));
                                        }
                                    }else{
                                        perror("Quinto processo não executado. \n");
                                        exit(0);
                                    }
                                }else if(t3>0){
                                    fclose(arq);
                                    wait(&N_freq);
                                    printf("Número de ocorrências no arquivo 3.txt: %d \n", oc3);
                                    exit(oc3 + WEXITSTATUS(N_freq));
                                }
                            }else{
                                perror("Quarto processo não executado. \n");
                                exit(0);
                            }
                        }else if(t2>0){
                            fclose(arq);
                            wait(&N_freq);
                            printf("Número de ocorrências no arquivo 2.txt: %d \n", oc2);
                            exit(oc2 + WEXITSTATUS(N_freq));
                        }
                    }else{
                        perror("Terceiro fork não executado. \n");
                        exit(0);
                    }
                }else if(t1>0){
                    fclose(arq);
                    wait(&N_freq);
                    printf("Número de ocorrências no arquivo 1.txt: %d \n", oc1);
                    exit(oc1 + WEXITSTATUS(N_freq));
                }
            }else{
                perror("Segundo fork não executado. \n");
                exit(0);
            }

        }else if(t0>0){
            wait(&N_freq);
            printf("Número de ocorrências no arquivo 0.txt: %d \n", oc0);
            printf("\nNúmero total de ocorrências no 5 arquivos: %d \n", oc0 + WEXITSTATUS(N_freq));
            exit(0);
        }

    }else{
        perror("Primeiro fork não executado. \n");
        exit(0);
    }

    return 0;

}
