#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define  MAX 150000                                       //Numero de buckets


struct Palavra {

        char word[42];
        struct Palavra* next;

};

//Declarando variveis globais
struct Palavra* aux;

//Inicializar o array
void Init(struct Palavra* pArray[MAX]){

        for (size_t i = 0; i < MAX; i++) {
                pArray[i] = NULL;
                pArray[i] = NULL;
        }
}

//Função de hash
unsigned long long hashCode(char* key){

        unsigned long long h = 0;
        for (unsigned long long i = 0; i < sizeof(key); i++) {

                h += key[i];
        }

        h +=75731;

        //printf("%lld\n", h);

        h = h%MAX;

        return h;

}

//Fução para inserção de palavras
void insert(FILE* stream, struct Palavra* pArray[MAX]){

        char p[42];
        int cont = 0;

        while (1) {

                fgets(p, 42, stream);
                if (feof(stream)) {
                        break;
                }

                if (p[strlen(p)-1] == '\n') {
                        p[strlen(p)-1] = '\0';

                }

                unsigned long long hash = hashCode(p);
                cont++;

                if (pArray[hash] != NULL) {

                        aux = pArray[hash];

                        aux = (struct Palavra*) malloc (sizeof(struct Palavra));
                        aux->next = pArray[hash];
                        strcpy(aux->next->word, p);
                        pArray[hash] = aux;


                } else {

                        pArray[hash] = (struct Palavra*) malloc (sizeof(struct Palavra));
                        strcpy(pArray[hash]->word, p);
                        pArray[hash]->next = NULL;

                }
        }

        printf("%d\n", cont);
}

int main(int argc, char const *argv[]) {

        struct Palavra* Dic[MAX];
        //struct Palavra* Doc[MAX];

        FILE* dic;

        dic = fopen("dicionario.txt", "r");

        if(dic == NULL) {

                puts("Falhou");
        }

        Init(Dic);
        //  Init(Doc);

        insert(dic, Dic);

        fclose(dic);

        int c = 0;
        int maior = 0;

        for (long int i = 0; i < MAX; i++) {

                if (Dic[i]) {
                        aux = Dic[i];

                        while (aux) {

                                c++;
                                aux = aux->next;
                        }
                        //printf("backet[%ld]=%d\n", i, c);

                        if(c > maior) {
                                maior = c;
                        }

                        c = 0;
                }

        }

        printf("%d\n", maior);

        return 0;
}
