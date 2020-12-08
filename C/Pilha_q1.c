#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

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
void Pop(struct Pilha* p){

    if(p->top >= 0){

        p->top--;

    }else{

        printf("String invalida\n");
        exit(1);
    }
}

int main(){

    char exp[MAX];
    struct Pilha p;

    p.top = -1;
   // while(1){

    printf("Digite a sequencia: ");
    fflush(stdin);
    fgets(exp, MAX, stdin);

    for(int i = 0; i<MAX; i++){
        if(exp[i] == '('){

            Push(&p, exp[i]);
        }

        else if(exp[i] == ')'){

            Pop(&p);
       }
    }

    printf("String valida\n");

    return 0;
}
