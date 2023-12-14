#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char nome[100], dtNasc[25], cursoUfes[100], periodoIngresso[10];
    int percConclusao;
    float CRA;
    int tamNome, tamCursoUfes, tamDtNasc, tamPeriodo;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **alunos = calloc(numeroAlunos, sizeof(Aluno *));
    for(int i=0; i < numeroAlunos; i++){
        alunos[i] = NULL;
    }
    return alunos;
}

int TamanhoString(char *string){
    int i=0;
    //while(string[i] != '\0'){
    while(string[i]){
        i++;
    }
    i++;
    return i;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *aluno = calloc (1, sizeof(Aluno));
    if(!aluno) exit(1);
    strcpy(aluno->periodoIngresso, periodoIngresso);
    strcpy(aluno->cursoUfes, cursoUfes);
    strcpy(aluno->dtNasc, dtNasc);
    strcpy(aluno->nome, nome);
    aluno->percConclusao = percConclusao;
    aluno->CRA = CRA;
    aluno->tamCursoUfes = TamanhoString(cursoUfes);
    aluno->tamDtNasc = TamanhoString(dtNasc);
    aluno->tamNome = TamanhoString(nome);
    aluno->tamPeriodo = TamanhoString(periodoIngresso);
    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    scanf("%*c");
    char nome[100], dtNasc[25], cursoUfes[100], periodoIngresso[10];
    int percConclusao;
    float CRA;
    for(int i=0; i < numeroAlunos; i++){
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", dtNasc);
        scanf("%[^\n]%*c", cursoUfes);
        scanf("%[^\n]%*c", periodoIngresso);
        scanf("%d%*c", &percConclusao);
        scanf("%f%*c", &CRA);
        vetorAlunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    if(alunos){
        for(int i=0; i < numeroAlunos; i++){
            free(alunos[i]);
        }
        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    int totalBytes=0;
    FILE *arq = fopen(fileName, "wb");

    if(arq == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        exit(1);
    }

    totalBytes += fwrite(&numeroAlunos, sizeof(int), 1, arq);

    for(int i=0; i < numeroAlunos; i++){
        totalBytes += fwrite(alunos[i], sizeof(Aluno), 1, arq);
        totalBytes += fwrite(alunos[i]->nome, sizeof(char), alunos[i]->tamNome, arq);
        totalBytes += fwrite(alunos[i]->cursoUfes, sizeof(char),  alunos[i]->tamCursoUfes, arq);
        totalBytes += fwrite(alunos[i]->dtNasc, sizeof(char), alunos[i]->tamDtNasc, arq);
        totalBytes += fwrite(alunos[i]->periodoIngresso, sizeof(char), alunos[i]->tamPeriodo, arq);
    }
    printf("Numero de bytes salvos: %d\n", totalBytes);
    fclose(arq);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE *arq = fopen(fileName, "rb");
    int numeroAlunos=0;
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        exit(1);
    }
    fread(&numeroAlunos, sizeof(int), 1, arq);
    for(int i=0; i < numeroAlunos; i++){
        Aluno *aluno = malloc(sizeof(Aluno));
        fread(aluno, sizeof(Aluno), 1, arq);
        fread(aluno->nome, sizeof(char), aluno->tamNome, arq);
        fread(aluno->cursoUfes, sizeof(char), aluno->tamCursoUfes, arq);
        fread(aluno->dtNasc, sizeof(char), aluno->tamDtNasc, arq);
        fread(aluno->periodoIngresso, sizeof(char), aluno->tamPeriodo, arq);
        alunos[i] = aluno;
    }
    fclose(arq);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    char c = '%';
    for(int i=0; i < numeroAlunos; i++){
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dtNasc);
        printf("Curso: %s\n", alunos[i]->cursoUfes);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%c Conclusao do Curso: %d\n", c, alunos[i]->percConclusao);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}

