#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void) {

    int *status;

    char *temp[] = {"hello", "Fulano", NULL};

    if (fork() != 0) {
        //processo pai
        /*
        Primeiro parametro de waitpid, valor inteiro: 
        -1      qualquer processo filho
         0      qualquer processo filho cujo ID de grupo seja igual ao do processo que invocou o waitpid 
         > 0    usara o valor passado como PID a aguardar
        */

       /*
        Segundo parametro de waitpid, endereco de variavel inteira (armazenara o valor de saida do processo filho)
       */

       /*
        Terceiro parametro de waitpid, valor inteiro (passar uma das constantes abaixo ou 0):
         WNOHANG     return immediately if no child has exited.

         WUNTRACED   also  return  if  a child has stopped (but not traced via ptrace(2)).  Status for traced children which have stopped is provided
                   even if this option is not specified.

         WCONTINUED (since Linux 2.6.10)
                   also return if a stopped child has been resumed by delivery of SIGCONT.
       */
        waitpid(-1, status, 0);
        printf("[EE] Esperei o processo filho (hello), e agora vou dormir 10s\n");
        
    } else {
        //processo filho
        execv("hello", temp);
    }

    printf("[EE] Saindo...\n");

    sleep(10);

    return 0;
}