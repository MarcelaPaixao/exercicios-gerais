#include <stdio.h>
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
    float media=0;
    float masc=0, fem=0, aprov=0;
    int total = VectorSize(alunos);
    char genero;
    
    for(int i=0; i < total; i++){
        media += GetNotaAluno(VectorGet(alunos, i));
        if(GetNotaAluno(VectorGet(alunos, i)) >= 6.0){
            aprov++;
        }
        
        genero = GetGeneroAluno(VectorGet(alunos, i));
        if(genero == 'F'){
            fem++;
        }
        else if(genero == 'M'){
            masc++;
        }
    }

    printf("Media das notas: %.2f\n", media/total);
    printf("Porcentagem de alunos aprovados: %.2f%\n", (aprov/total)*100);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%\n", (masc/total)*100);
    printf("Feminino: %.2f%\n", (fem/total)*100);
    printf("Outro: %.2f%\n", (total - masc - fem)/total*100);
}


