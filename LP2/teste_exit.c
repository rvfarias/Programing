#include <stdio.h>
#include <stdlib.h>

int main (void){

   //int iValor_a;
   //int iValor_b;
   int aux = 0;

   char str[5] = {'a', 'b', 'c', 'd', '\0'};

   while (aux < 4) {

     printf("%s\n", str);
     printf("%c\n", str[aux]);
     aux++;

   }
/*
   while (1)
   {
      printf("Valores:");
      scanf("%d %d", &iValor_a, &iValor_b);

      if (iValor_a == 0)
      {
         exit(0);
      }
      if (iValor_b == 0)
      {
         exit (11);
      }
      printf("Divisao : %d\n", iValor_a / iValor_b);
   }
*/
   return 0;
}
