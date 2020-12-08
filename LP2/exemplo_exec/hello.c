#include <stdio.h>
#include <unistd.h>

/*
    Programa a ser invocado pelo exemplo de uso da funcao execv

*/

int main(int argc, char* argv[]) {
    printf("[HELLO] Exec name: %s\n", argv[0]);

    if (argc > 1) {
        printf("[HELLO] Hello %s\n", argv[1]);
    }

    printf("[HELLO] Vou dormir 30s\n");

    sleep(30);

    printf("Dormi e agora vou terminar\n");


    return 0;
}