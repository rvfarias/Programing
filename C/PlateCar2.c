#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 5

struct PlateCar {
        char plate[8];
        struct PlateCar* next;
};

struct PlateCar* plateArray[SIZE];
struct PlateCar* item;
//struct DataItem* dummyItem;


unsigned int hashCode(char* key){

        unsigned int h = 0;
        int p = 1;

        for (int i = 6; i >= 3; i--) {

                char c = key[i];
                int aux = c;
                h = h + aux *p;
                p *= 10;

        }

        for (int i = 2; i >= 0; i--) {

                h = h + (key[i] - 'A') * p;
                p *= 26;

        }

        return h % SIZE;
}

void Init(){

        for (size_t i = 0; i < SIZE; i++) {
                plateArray[i] = NULL;
        }
}

void insert(char* p){

        int hashIdex;
        hashIdex = hashCode(p);
        printf("%d\n", hashIdex);

        if (plateArray[hashIdex] != NULL) {

              item = plateArray[hashIdex];

                while (item->next) {

                        item = item->next;
                }

                item->next = (struct PlateCar*) malloc (sizeof(struct PlateCar));
                strcpy(item->next->plate, p);
                item->next->next = NULL;




        }else{

                plateArray[hashIdex] = (struct PlateCar*) malloc (sizeof(struct PlateCar));
                strcpy(plateArray[hashIdex]->plate, p);
                plateArray[hashIdex]->next = NULL;

        }



}
/*
   struct DataItem *search(int key){

        int hashIdex = hashCode(key);

        while(hashArray[hashIdex] != NULL) {

                if (hashArray[hashIdex]->key == key) {

                        return hashArray[hashIdex];
                }

 ++hashIdex;

                hashIdex %= SIZE;

        }

        return NULL;

   }
 */
void Display() {

        for (size_t i = 0; i < SIZE; i++) {

                if (plateArray[i]) {

                        item = plateArray[i];

                        while (item) {

                                printf("Placa: %s\n", item->plate);
                                item = item->next;

                        }
                }

        }
}

int main(int argc, char const *argv[]) {

        //dummyItem = (struct DataItem*) malloc (sizeof(struct DataItem));
        //dummyItem->data = -1;
        //dummyItem->key = -1;
        Init();
        insert("NWL5356");
        insert("QBH2709");
        insert("ZOW6261");
        insert("IDD2023");
        insert("XRJ2289");
        insert("AAA0000");
        insert("AAA0000");
        insert("AAA0000");
/*
        item = search(37);

        if (item != NULL) {

                printf("Item encontrado: %d\n", item->data);

        } else {

                printf("Item nao encontrado:\n");

        }
 */
        Display();

        return 0;
}
