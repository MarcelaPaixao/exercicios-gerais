#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic {
    void *vetor;
    int tam;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen = malloc(sizeof(tGeneric));
    if(gen == NULL){
        exit(1);
    }
    gen->tam = numElem;
    gen->tipo = type;
    gen->vetor = malloc(numElem * sizeof(type));
    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    if(gen != NULL){
        free(gen->vetor);
        free(gen);
    }
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");
    for(int i=0; i < gen->tam; i++){
        if(gen->tipo == INT){
            scanf("%d", (int*)gen->vetor + i);
        }
        else if(gen->tipo == FLOAT){
            scanf("%f", (float*)gen->vetor + i);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    for(int i=0; i < gen->tam; i++){
        if(gen->tipo == INT){
            printf("%d ", ((int*)gen->vetor)[i]);
        }
        else if(gen->tipo == FLOAT){
            printf("%.2f ", ((float*)gen->vetor)[i]);
        }
    } 
}

