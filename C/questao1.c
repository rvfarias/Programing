#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct List{
    struct Node *head;
    int size;
}Node;

int main(void){

    Node *n1 = NULL;

    return 0;
}

void Append(Node** n, int data){

    if(n!=NULL){
        Node *aux=*n; 
        while(aux->next){
            aux=aux->next;
        }
        aux->next = (Node*) malloc(sizeof(Node));
        aux->next->data = data;
        aux->next->next = NULL; 
    }

    else{
        *n = (Node*) malloc(sizeof(Node));
        (*n)->next=NULL;
        (*n)->data=data;
    }
}

void Preppend(Node**n, int data){

    if(n!=NULL){
        Node *aux = (Node*) malloc(sizeof(Node));
        aux->data=data;
        aux->next=*n;
        *n=aux; 
    }
    else{
        *n = (Node*) malloc(sizeof(Node));
        (*n)->data=data;
        (*n)->next=NULL;
    }
}

void InsertAfter(Node**n, int data){

    Node *new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->next = n->next;
    n->next = new;
}

void Remove(Node** n, )

