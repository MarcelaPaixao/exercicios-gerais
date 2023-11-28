#include <stdio.h>
#include "relatorio.h"
#include "vector.h"
#include "aluno.h"

int main(){
    int qtdAlunos=0;
    scanf("%d\n", &qtdAlunos);

    Vector *vetAlunos = VectorConstruct();

    for(int i=0; i < qtdAlunos; i++){
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetAlunos, aluno);
    }
    
    ImprimeRelatorio(vetAlunos);

    VectorDestroy(vetAlunos, DestroiAluno);

    return 0;
}