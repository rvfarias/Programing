#include <stdlib.h>
#include <stdio.h>

#define SIZE 20

struct DataItem {
        int data;
        int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
        return key % SIZE;
}


void insert(int key, int data){

        struct DataItem *item = (struct DataItem*) malloc (sizeof(struct DataItem));
        item->data = data;
        item->key = key;

        int hashIdex = hashCode(key);

        while(hashArray[hashIdex] != NULL && hashArray[hashIdex]->key != -1) {

                ++hashIdex;

                hashIdex %= SIZE;
        }

        hashArray[hashIdex] = item;

}

void Delete(struct DataItem* item) {

        int key = item->key;

        int hashIdex = hashCode(key);

        while(hashArray[hashIdex] != NULL) {

                if (hashArray[hashIdex]->key == key) {

                        hashArray[hashIdex] = dummyItem;

                }

                ++hashIdex;
                hashIdex %= SIZE;

        }
}

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

void Display() {

        for (int i = 0; i < SIZE; i++) {
                if (hashArray[i] != NULL) {

                        printf("Item: %d\nChave: %d\n", hashArray[i]->data, hashArray[i]->key);

                }

        }
}
int main(int argc, char const *argv[]) {

        dummyItem = (struct DataItem*) malloc (sizeof(struct DataItem));
        dummyItem->data = -1;
        dummyItem->key = -1;

        insert(1, 20);
        insert(2, 70);
        insert(42, 80);
        insert(4, 25);
        insert(12, 44);
        insert(14, 32);
        insert(17, 11);
        insert(13, 78);
        insert(37, 97);

        item = search(37);

        if (item != NULL) {

                printf("Item encontrado: %d\n", item->data);

        } else {

                printf("Item nao encontrado:\n");

        }

        printf("\n");

        Display();
        Delete(item);

        printf("\n");

        item = search(37);

        if (item != NULL) {

                printf("Item encontrado: %d\n", item->data);

        } else {

                printf("Item nao encontrado:\n");

        }

        printf("\n");

        Display();

        return 0;
}
