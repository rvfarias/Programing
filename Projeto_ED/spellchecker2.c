#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define  MAX 157351                                       //Numero de buckets


struct Palavra {

        char word[42];
        struct Palavra* next;

};

//Declarando variveis globais
struct Palavra* aux;

//Inicializar o array
void Init(struct Palavra** pArray){

        for (size_t i = 0; i < MAX; i++) {
                pArray[i] = NULL;
        }
}

//Limpando a string
void clear(char* str) {

        for (int i = 0; i < 45; i++) {
                str[i] = 0;

        }
}

//Função de hash
unsigned long long hashCode(char* key){

        unsigned long long h = 0;
        for (unsigned long long i = 0; i < strlen(key); i++) {

                h += key[i];
        }

        h = h % MAX;

        return h;

}

//Armazenar o dicionario para comparação
void alocDic(FILE* stream, struct Palavra** pArray){

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

                for (size_t i = 0; i < strlen(p); i++) {

                        p[i] = tolower(p[i]);

                }

                unsigned long long hash = hashCode(p);
                cont++;

                if (pArray[hash] != NULL) {

                        aux = pArray[hash];

                        aux = (struct Palavra*) malloc (sizeof(struct Palavra));
                        aux->next = pArray[hash];
                        strcpy(aux->word, p);
                        pArray[hash] = aux;


                } else {

                        pArray[hash] = (struct Palavra*) malloc (sizeof(struct Palavra));
                        strcpy(pArray[hash]->word, p);
                        pArray[hash]->next = NULL;

                }
        }

        printf("%d\n", cont);
}

//Fução de verifição
int check(char* w, struct Palavra** pArray){

        int wHash = hashCode(w);

                aux = pArray[wHash];

                while (aux) {

                        if (!strcmp(aux->word, w)) {

                                return 1;

                        }

                        aux = aux->next;

                }


        return 0;
}


   //Printa todos os elementos do array
   void Display(struct Palavra** pArray) {

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
/*
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

                        if(c > maior) {
                                maior = c;
                        }

                        c = 0;
                }
        }

        printf("%d\n", maior);

   }

 */
int main(int argc, char const *argv[]) {

        struct Palavra* Dic[MAX];

        //clock_t t;

        FILE* dic;
        FILE* doc;

        dic = fopen("dicionario.txt", "r");
        doc = fopen("textoforcheck.txt", "r");

        int total = 0;
        int inc = 0;

        if(doc == NULL || dic == NULL) {

                puts("Falhou");
        }

        Init(Dic);
        alocDic(dic, Dic);

        char word[42];
        clear(word);

        int w;
        int i = 0;

        //t = clock();

        while (w != EOF) {


                w = fgetc(doc);

                if (isdigit(w)) {

                        continue;
                }

                else if (isalpha(w) || ((w == '-' || w == '\'') && i > 0)){
                        word[i] = w;
                        i++;

                }

                else if(i > 0) {

                        int x;

                        total++;

                        word[i] = '\0';

                        for (size_t i = 0; i < strlen(word); i++) {

                                word[i] = tolower(word[i]);

                        }
                        //printf("%s\n", word);

                        x = check(word, Dic);

                        if (!x) {
                                inc++;
                                //printf("%s\n", word);

                        }


                        i = 0;
                        clear(word);

                }

        }

        //t = clock() - t;

        fclose(doc);
        fclose(dic);

        //Display(Dic);

        printf("Total de palavras verificadas: %d\n", total);
        printf("Total de palavras erradas: %d\n", inc);

        //printf("%lf\n",((double)t)/((CLOCKS_PER_SEC/1000)));
        return 0;
}
