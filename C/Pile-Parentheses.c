#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct pile{
    int value;
    struct pile* next;
}pilha;

typedef struct head{
    int size;
    pilha *begin;
}headPile;

int empilhando(headPile *m, int value){
    pilha *element;
    element = (pilha*) malloc(sizeof(pilha));

    element->value = value;
    element->next = m->begin;
    m->begin = element;
    m->size++;

    return m->size;
}

int desimpilhando(headPile *m){
    pilha *remov;

    if(m->size == 0)
        return -1; 
    
    remov = m->begin;
    m->begin = m->begin->next;

    free(remov);
    m->size--;

    return m->size;
}

int main(){
    headPile *amount;
    char array[MAX];
    int aux;

    amount = (headPile*) malloc(sizeof(headPile));

    amount->begin = NULL;
    amount->size = 0;

    printf("Digite a sequencia: ");
    fgets(array,MAX,stdin);

    for(int i=0;i<MAX;i++){
        if( array[i] == '(')
            aux = empilhando(amount,1);

        else if( array[i] == ')')
            aux = desimpilhando(amount);
        
        if(aux < 0)
            break;
    }

    if(aux == 0){
        printf("Correto\n");
    }else{
        printf("Incorreto\n");
    }

    return 0;
}