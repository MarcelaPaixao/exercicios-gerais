#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "relatorio.h"
#include "vector.h"
#include "aluno.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
    float media=0, aprov=0;
    int masc=0, fem=0;
    char genero;
    for(int i=0; i < VectorSize(alunos); i++){
        media += GetNotaAluno(VectorGet(alunos, i));
        genero = GetGeneroAluno(VectorGet(alunos, i));
    if(genero == 'F'){
        fem++;
    }
    else if(genero == 'M'){
        masc++;
    }

        
    }
    media = media/VectorSize(alunos);


}


