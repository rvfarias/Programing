#include <stdlib.h>
#include <stdio.h>

struct Node {

        int value;
        struct Node* next;

};

void Append(struct Node** n, int v){

        if(!*n) {

                *n = (struct Node*) malloc (sizeof (struct Node));
                (*n)->value = v;
                (*n)->next = NULL;

        }else{

                struct Node *aux = *n;

                if (!aux->next) {

                        aux->next = (struct Node*) malloc (sizeof (struct Node));
                        aux->next->value = v;
                        //aux->next->next = NULL;

                } else {

                        while(aux->next) {

                                aux = aux->next;
                        }

                        aux->next = (struct Node*) malloc (sizeof (struct Node));
                        aux->next->value = v;
                        aux->next->next = NULL;
                }

        }


}

int main(){

        struct Node *n1 = NULL;

        Append(&n1, 1);
        Append(&n1, 2);
        Append(&n1, 3);
        Append(&n1, 4);

        struct Node *aux = n1;

        while(aux != NULL) {

                printf("%d\n", aux->value);
                aux = aux->next;

        }

        printf("\nHello world!\n");

        return 0;
}
