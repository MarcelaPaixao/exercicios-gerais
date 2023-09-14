#include "aluno.h"
#include <stdio.h>

int main(){
    int qtdAlunos=0, i=0, j=0;

    scanf("%d", &qtdAlunos);
    tAluno listaAlunos[qtdAlunos], auxAluno;
    
    for(i = 0; i < qtdAlunos; i++){
        listaAlunos[i] = LeAluno;
    }

    for(i = 0; i < qtdAlunos-1; i++){
        for(j = i+1; j < qtdAlunos; j++){
            if(ComparaMatricula(listaAlunos[j], listaAlunos[i]) < 0){
                auxAluno = listaAlunos[i];
                listaAlunos[i] = listaAlunos[j];
                listaAlunos[j] = auxAluno;
            }
        }
    }

    for(i = 0; i < qtdAlunos; i++){
        if(VerificaAprovacao(listaAlunos[i])){
            ImprimeAluno(listaAlunos[i]);
        }
    }
    
    return 0;
}