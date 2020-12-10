#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define  MAX 150000                                       //Numero de buckets


struct Palavra {

        char word[42];
        struct Palavra* next;

};

struct Palavra* aux;

//Inicializar o array
void Init(struct Palavra* pArray[MAX]){

        for (size_t i = 0; i < MAX; i++) {
                pArray[i] = NULL;
        }
}

//Limpando a string
void clear(char str[]) {

        for (int i = 0; i < 45; i++) {
                str[i] = 0;

        }
}

//Função de hash
unsigned long long hashCode(char* key){

        unsigned long long h = 0;
        for (unsigned long long i = 0; i < sizeof(key); i++) {

                h += key[i];
        }

        h = h % MAX;

        return h;

}

//Fução para inserção de palavras
void insert(FILE* stream, struct Palavra* pArray[MAX]){

        char p[42];
        clear(p);

        int w;
        int cont = 0;
        int i = 0;

        while (1) {

                w = fgetc(stream);

                if (feof(stream)) {
                        break;
                }

                if (w == ',' || w == '!' ||  w == '(' || w == ')' || w == '/' || w == '.'|| w == '?' || w == ':' || w == ';'|| w == '['|| w == ']'|| w == '"' || w == '0' || w == '1'|| w == '2'|| w == '3'|| w == '4'|| w == '5'|| w == '6'|| w == '7'|| w == '8'|| w == '9') {

                        continue;

                }

                else if ((w == ' ' || w == '\n') && strlen(p) > 1) {

                        unsigned long long hash = hashCode(p);
                        p[i] = '\0';
                        i = 0;
                        cont++;
                        //printf("%lld\n", hash);


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

                        clear(p);

                } else {

                        p[i] = w;
                        i++;

                }

        }

        printf("%d\n", cont);
}

//Fução de comparação


//Printa todos os elementos do array
void Display(struct Palavra* pArray[MAX]) {

        for (size_t i = 0; i < MAX; i++) {

                if (pArray[i]) {

                        aux = pArray[i];

                        while (aux) {
                                printf("Placa: %s\n", aux->word);
                                //for (size_t i = 0; i < strlen(aux->word); i++) {

                                //printf("%c",aux->word[i]);
                                //}
                                //  printf("\n");
                                aux = aux->next;

                        }
                }

        }
}

//Printa a quantidade do maior bucket
void quant(struct Palavra* pArray[MAX]) {

        int c = 0;
        int maior = 0;

        for (long int i = 0; i < MAX; i++) {

                if (pArray[i]) {
                        aux = pArray[i];

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

}


int main(int argc, char const *argv[]) {

        struct Palavra* Dic[MAX];

        FILE* dic;
        FILE* doc;
        dic = fopen("dicionario.txt", "r");
        doc = fopen("textoforcheck.txt", "r");

        if(doc == NULL || dic == NULL) {

                puts("Falhou");
        }

        Init(Dic);

        fclose(doc);
        fclose(dic);


        return 0;
}
