#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int numAlunos=0;

    printf("Digite o numero de alunos: ");
    scanf("%d", &numAlunos);
    Aluno **alunos = CriaVetorAlunos(numAlunos);
    LeAlunos(alunos, numAlunos);
    SalvaAlunosBinario(alunos, "alunos.bin", numAlunos);

    LiberaAlunos(alunos, numAlunos);

    Aluno **alunos2 = CriaVetorAlunos(numAlunos);
    CarregaAlunosBinario(alunos2, "alunos.bin");
    ImprimeAlunos(alunos2, numAlunos);
    LiberaAlunos(alunos2, numAlunos);
    
    return 0;
}