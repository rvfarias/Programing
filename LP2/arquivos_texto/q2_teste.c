#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int copy1, copy2, copy3, copy4, total = 0;
  int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0, cont5 = 0;
  char str1[11], str2[11];
  FILE *fp1;

    printf("Digite a sequencia de caracteres(max 10):");
    fgets(str1, 11, stdin);
    str1[strlen(str1)-1] = '\0';

    fp1 = fopen("0.txt", "r");
    if(fp1 == NULL){
       printf("Erro!!");
    }

    printf("Lendo arquivo 1\n");
    while(fgets(str2, 11, fp1) != NULL){

      str2[strlen(str2)-1] = '\0';

      if(!strcmp(str1, str2)){
  	     cont1++;
      }
    }
      copy1 = fork();

      if (copy1 == 0) {

          //FILE *fp2;
          fp1 = fopen("1.txt", "r");

          printf("Lendo arquivo 2\n");
          while(fgets(str2, 11, fp1) != NULL){

            str2[strlen(str2)-1] = '\0';

            if(!strcmp(str1, str2)){
        	     cont2++;
            }
          }

          copy2 = fork();

          if (copy2 == 0) {

              //FILE *fp3;
              fp1 = fopen("2.txt", "r");

              printf("Lendo arquivo 3\n");
              while(fgets(str2, 11, fp1) != NULL){

                str2[strlen(str2)-1] = '\0';

                if(!strcmp(str1, str2)){
                   cont3++;
                }
              }

                copy3 = fork();

                if (copy3 == 0) {
                  //FILE *fp4;
                  fp1 = fopen("3.txt", "r");

                  printf("Lendo arquivo 4\n");
                  while(fgets(str2, 11, fp1) != NULL){

                    str2[strlen(str2)-1] = '\0';

                    if(!strcmp(str1, str2)){
                       cont4++;
                    }
                  }

                    copy4 = fork();

                    if (copy4 == 0) {

                      //FILE *fp5;
                      fp1 = fopen("4.txt", "r");

                      printf("Lendo arquivo 5\n");
                      while(fgets(str2, 11, fp1) != NULL){

                        str2[strlen(str2)-1] = '\0';

                        if(!strcmp(str1, str2)){
                           cont5++;
                        }

                        fclose(fp1);
                        printf("\nNumero de palavras no arquivo 5: %d", cont5);
                        exit(cont5);

                      }

                    } else {
                      fclose(fp1);
                      wait(&total);
                      printf("\nNumero de palavras no arquivo 4: %d", cont4);
                      exit(cont4+WEXITSTATUS(total));
                    }
                } else {
                  fclose(fp1);
                  wait(&total);
                  printf("\nNumero de palavras no arquivo 3: %d", cont3);
                  exit(cont3+WEXITSTATUS(total));
                }

          } else {

            fclose(fp1);
            wait(&total);
            printf("\nNumero de palavras no arquivo 2: %d", cont2);
            exit(cont2 + WEXITSTATUS(total));
          }

    } else {
      
      fclose(fp1);
      wait(&total);
      printf("\nNumero de palavras no arquivo 1: %d", cont1);
      printf("\n");
      printf("\nNumero de frequencias: %d\n", WEXITSTATUS(total) + cont1);
      exit(0);
    }

    return 0;
}
