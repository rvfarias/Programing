#include<stdio.h>
#define Q_ALUNOS 6

typedef struct{
    char nome[32];
    int Mat;
    float Nota[3];
    } tDados;

float Media(tDados Nota){
    return (Nota.Nota[0]+Nota.Nota[1]+Nota.Nota[2])/3;
}

float Mturma(int turma[], int t){
    int i;
    float soma=0;
    for(i=0; i<t; i++){
        soma+=turma[i];
    }
    return soma/t;
}

int main(){

    int i;

    tDados aluno[Q_ALUNOS];

    int turma[Q_ALUNOS];

    FILE *fp, *saida;

    fp = fopen("alunos.txt", "r");

    if(fp == NULL){
        puts("nao foi");
    }

    saida = fopen("relatorio.txt", "w");

    if(saida == NULL){
        puts("nao foi");
    }

    for(i=0; i<Q_ALUNOS; i++){
        fgets(aluno[i].nome, "%s", fp);
        fscanf(fp,"%d", &aluno[i].Mat);
        fscanf(fp,"%f %f %f%*c\n", &aluno[i].Nota[0], &aluno[i].Nota[1], &aluno[i].Nota[2]);

        turma[i]=Media(aluno[i]);
    }
    for(i=0; i<Q_ALUNOS; i++){
        fprintf(saida,"Aluno: %s", aluno[i].nome);
        fprintf(saida,"Matricula do aluno: %d\n", aluno[i].Mat);
        fprintf(saida,"Media do aluno: %.2f\n", Media(aluno[i]));
        if(Media(aluno[i])>=7){
            fprintf(saida,"Aprovado\n\n");
        }else{
            fprintf(saida,"Reprovado\n\n");
        }

    }
    fprintf(saida,"Media da turma: %.2f\n", Mturma(turma, Q_ALUNOS));

    fclose(fp);
    fclose(saida);

    return 0;
}
