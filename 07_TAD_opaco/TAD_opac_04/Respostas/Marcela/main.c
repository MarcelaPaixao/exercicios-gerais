#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void OrdenaVetor(tAluno **listaAlunos, int tam){
    tAluno * auxAluno = NULL;
    for(int i = 0; i < tam-1; i++){
        for(int j = i+1; j < tam; j++){
            if(ComparaMatricula(listaAlunos[j], listaAlunos[i]) < 0){
                auxAluno = listaAlunos[i];
                listaAlunos[i] = listaAlunos[j];
                listaAlunos[j] = auxAluno;
            }
        }
    }
}

int main(){
    int tam=0, i, j;

    scanf("%d", &tam);

    tAluno **listaAlunos = (tAluno **)malloc(tam * sizeof(tAluno*));

    for(i=0; i < tam; i++){
        listaAlunos[i] = CriaAluno();
        LeAluno(listaAlunos[i]);
    }

    OrdenaVetor(listaAlunos, tam);
    
    for(i = 0; i < tam; i++){
        if(VerificaAprovacao(listaAlunos[i])){
            ImprimeAluno(listaAlunos[i]);
        }
    }

    for(i = 0; i < tam; i++){
        ApagaAluno(listaAlunos[i]);
    }
    free(listaAlunos);
    
    return 0;
}