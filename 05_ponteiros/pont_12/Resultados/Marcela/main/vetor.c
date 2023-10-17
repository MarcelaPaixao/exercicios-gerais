#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Lê um vetor da entrada padrão.
 * 
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor){
    scanf("%d", &vetor->tamanhoUtilizado);

    for(int i = 0; i < vetor->tamanhoUtilizado; i++){
        scanf("%d", &vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 * 
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
*/
int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int result=vetor->elementos[0];
    
    for(int i=1; i < vetor->tamanhoUtilizado; i++){
        result = op(vetor->elementos[i], result);
    }
    
    return result;
}

