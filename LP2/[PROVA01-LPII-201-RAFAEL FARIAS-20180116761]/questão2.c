#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <time.h>

//Função de execução das threads
void* print(void* x) {

  printf("Nova thread\n");

}

int main(int argc, char const *argv[]) {

  //Variável que armazenara o pid do processo pai
  int pid_parent;
  pthread_t thread[30];
  //Variáveis de contagem do tempo
  clock_t inic1, final1;
  clock_t inic2, final2;
  int i;

  pid_parent = getpid();

  inic1 = clock();

  //Loop para ciração das threads
  for (i = 0; i < 30; i++) {
    pthread_create(&thread[i], NULL, print, NULL);
    pthread_join(thread[i], NULL);
    sleep(2);

  }

  final1 = clock();

  inic2 = clock();
  //Loop para invoção dos processos
  for (i = 0; i <= 30; i++) {
    //Limitando ao pai a criação de novos processos
    if (getpid() == pid_parent) {

      fork();
      sleep(2);

    }else{

      printf("Novo processo\n");
      exit(0);

    }
  }
  final2 = clock();

  //Limitando ao processo pai os print
  if (i == 31 && getpid() == pid_parent) {
    //Printando o tempo de execução de cada loop
    printf("Tempo das threads: %lf segundos\n", ((double)(final1 - inic1)/((double)CLOCKS_PER_SEC)));
    printf("Tempo dos forks: %lf segundos\n", ((double)(final2 - inic2)/((double)CLOCKS_PER_SEC)));
  }

  return 0;

}

/*
Por demandar de uma maior quantidade de recursos era de se esperar que tempo de execução do fork fosse bem maior
e podemos compravar isso com os resultados obtidos.
 
As principais diferenças entre threads e processos, são no uso dos recursos do computador, visto que as threads
são mais econômicas, o tempo de vida dos processos são independentes, enquanto as threads dependem do processo
que as invoca e o compatilhamneto de informações visto que as threads compartilham a memoria do programa concorrente,
já os processos possuem sua própria região de memória.
*/
