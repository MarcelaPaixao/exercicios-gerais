#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

struct Aluno {
    char nome[50];
    float nota;
    char genero;
};

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno(){
    tAluno *aluno = malloc(sizeof(tAluno));
    if(aluno == NULL){
        printf("Falha na alocacao!\n");
        exit(1);
    }
    aluno->nota = 0;
    aluno->genero = '\0';
    return aluno;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno){
    if(aluno != NULL){
        free((tAluno*)aluno);
    }
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno){
    scanf("%[^;];%c;%f",aluno->nome, &aluno->genero, &aluno->nota);
    scanf("\n");
}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}


