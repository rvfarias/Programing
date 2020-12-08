#include <stdlib.h>
#include <stdio.h>

struct Node {

        int value;
        struct Node* next;
};

struct Node* head = NULL;
struct Node* current = NULL;

void Insert(int v){

        struct Node *aux = (struct Node*) malloc(sizeof(struct Node));
        aux->value = v;

        aux->next = head;
        head = aux;
}

void InsertEnd(int v){

        if (current == NULL) {

                struct Node* aux = (struct Node*) malloc(sizeof(struct Node));
                aux->value = v;

                aux->next = current;
                current = aux;

        } else {

                struct Node *aux = current;

                while(aux->next) {

                        aux = aux->next;

                }
                aux->next = (struct Node*) malloc (sizeof (struct Node));
                aux->next->value = v;
                aux->next->next = NULL;
        }



}

int main(){

        Insert(1);
        Insert(2);
        Insert(3);
        Insert(4);
        Insert(5);

        InsertEnd(1);
        InsertEnd(2);
        InsertEnd(3);
        InsertEnd(4);
        InsertEnd(5);

        struct Node *aux = head;

        while(aux != NULL) {


                printf("%d\n", aux->value);
                aux = aux->next;

        }

        aux = current;
        while(aux != NULL) {


                printf("%d\n", aux->value);
                aux = aux->next;

        }

        printf("\nHello world!\n");

        return 0;
}
