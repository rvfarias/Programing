#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

//PID DO PROCESSO PAI
void type_prompt()
{
   printf("Processo pai, pid: %d\n", getpid());
}

int main(){
    int status, pid;
    char *args[] = {"ps", " -a", NULL}; //ARGUMENTOS PRO EXECVE

    while(1){
       type_prompt();
       sleep(5);

        if( (pid = fork()) != 0){
            printf("Esperando o processo filho acabar, PID = %d\n", pid);
            waitpid(-1, &status, 0);
            sleep(3);
            printf("\nProcesso filho acabou, começando a criação de outro. \n\n");
        }else{
            sleep(30);
            printf("Executando comando do execve: \n\n");
            execve("ls", args, NULL);
            printf("Error\n");
            exit(0);
        }
    }

    return 0;
}
