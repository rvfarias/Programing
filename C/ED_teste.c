#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Pilha{

    char str[MAX];
    int top;

};

void Push(struct Pilha* p, char c){

    if(p->top == (MAX-1)){

        printf("Pilha cheia!\n");
        exit(1);

    }else{

        p->top++;
        p->str[p->top] = c;
    }
}

char* Pop(struct Pilha* p){

    if(p->top >= 0){
        char *aux = (char *)malloc(strlen(p->str));

        for(unsigned int i = 0; i<strlen(p->str); i++){
             aux[i] = p->str[p->top];
             p->top--;
        }

        return aux;

    }else{

        printf("Pilha vazia\n");
        exit(1);
    }
}

int main(){

    struct Pilha *p;
    char exp[MAX];
    char *str1;

    printf("Digite a frase: ");
    fflush(stdin);
    fgets(exp, MAX, stdin);

    for(unsigned int i = 0; i<strlen(exp); i++){

        Push(p, exp[i]);
    }

        str1 = Pop(p);
        printf("%s", str1);

    return 0;
}
