#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  
        //FILE *fp2;
        fp1 = fopen("1.txt", "r");

        printf("Lendo arquivo 2\n");
        while(fgets(str2, 11, fp1) != NULL) {

                str2[strlen(str2)-1] = '\0';

                if(!strcmp(str1, str2)) {
                        cont2++;
                }
        }

        copy2 = fork();

        if (copy2 == 0) {

                //FILE *fp3;
                fp1 = fopen("2.txt", "r");

                printf("Lendo arquivo 3\n");
                while(fgets(str2, 11, fp1) != NULL) {

                        str2[strlen(str2)-1] = '\0';

                        if(!strcmp(str1, str2)) {
                                cont3++;
                        }
                }

                copy3 = fork();

                if (copy3 == 0) {
                        //FILE *fp4;
                        fp1 = fopen("3.txt", "r");

                        printf("Lendo arquivo 4\n");
                        while(fgets(str2, 11, fp1) != NULL) {

                                str2[strlen(str2)-1] = '\0';

                                if(!strcmp(str1, str2)) {
                                        cont4++;
                                }
                        }

                        copy4 = fork();

                        if (copy4 == 0) {

                                //FILE *fp5;
                                fp1 = fopen("4.txt", "r");

                                printf("Lendo arquivo 5\n");
                                while(fgets(str2, 11, fp1) != NULL) {

                                        str2[strlen(str2)-1] = '\0';

                                        if(!strcmp(str1, str2)) {
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


        return 0;
}
