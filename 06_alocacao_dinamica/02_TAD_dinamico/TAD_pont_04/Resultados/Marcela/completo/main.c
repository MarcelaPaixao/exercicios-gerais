#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void OrdenaAlunos(tAluno *alunos, int tam){
    tAluno temp;
    for(int i=0; i < tam; i++){
        for(int j = 0; j < tam-i-1; j++){
            if(ComparaMatricula(&alunos[j], &alunos[j+1]) == 1){
                temp = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = temp;
            }
        }
    }
}

void ImprimeListaAlunos(tAluno *alunos, int tam){
    for(int i=0; i < tam; i++){
        if(VerificaAprovacao(&alunos[i])){
            ImprimeAluno(&alunos[i]);
        }
    }
}

int main (){
    int qtdAlunos=0, i;

    scanf("%d", &qtdAlunos);

    tAluno * alunos = (tAluno *) malloc(sizeof(tAluno));
    
    for(i=0; i < qtdAlunos; i++){
        alunos[i] = *CriaAluno();
        LeAluno(&alunos[i]);
    }

    OrdenaAlunos(alunos, qtdAlunos);
    ImprimeListaAlunos(alunos, qtdAlunos);

    for(i=0; i < qtdAlunos; i++){
        ApagaAluno(&alunos[i]);
    }
    
    free(alunos);
    return 0;
}