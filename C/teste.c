#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX 60

int main(){
  char str[7];
  char str1[4];
  char str2[4];

  setlocale(LC_ALL, "Portuguese");

        srand(time(NULL));

        int x;

           for (int i = 0; i < 6; i++) {
                x = (rand() % 90);
                if (x < 26) {
                  x+=65;
                }
                else if(x < 52){
                  x+=39;
                }
                else if(x < 65){
                  x+=13;
                }
                str[i] = x;

                if (i == 5) {

                  str[6] = '\0';
                }

                        //srand(time(NULL));

           }
           printf("%s\n", str);

           fgets(str, 7, stdin);
            int j = 5;
           for (size_t i = 0; i < 3; i++) {

             str1[i] = str[i];
             str2[i] = str[j];
             j--;
           }

           str1[3] = '\0';
           str2[3] = '\0';

           printf("%s\n%s\n", str1, str2);

           if (!strcmp(str1, str2)) {
             printf("TRUE\n");
           }
/*
           x = rand() % 31;

           printf("\n\n%d\n", x);




           char* x = (char*) malloc (sizeof(char));
           unsigned int h = 0;
           int p = 1;

           fgets(x, 8, stdin);

           for (int i = 6; i >= 3; i--) {

           char c = x[i];
           printf("%d\n", i);
           int aux = c;
           h = h + aux *p;
           p *= 10;


           }

           printf("%d\n", h);



        char c[3] = "FF";
        int x = 0;
        for (size_t i = 0; i <= 3; i++) {
          x += c[i];
          printf("%d\n",x);

        }
        printf("%d\n",x);
        printf("%s\n", c);
*/
        return 0;


}
