#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TRUE 1

int id = 0;
int pid;
char *argv[];
char str[256];

void type_prompt()
{
   printf("PID do processo pai: %d", getpid());
   printf("\n");
}

void read_command() {

  id = 0;

  gets(str);
  argv[id++] = strtok (str," ");

  while (argv[id-1] != NULL){
    argv[id++] = strtok (NULL, " ");

  }

}

int main(){

  int status;

   while (TRUE) {

      type_prompt();
      read_command();

       if(fork() != 0){

           waitpid(-1, &status, 0);

       }else{

           execvp(argv[0], argv);
           printf("Comando desconhecido\n");
           exit(0);
       }
   }
   return 0;
}
