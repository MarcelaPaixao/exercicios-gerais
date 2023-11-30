#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct pacote{
    Type tipo;
    int tam, soma;
    void* vetor;
};

tPacote* CriaPacote(Type type, int numElem){
    tPacote* pacote = malloc(sizeof(tPacote));
    if(pacote == NULL){
        exit(1);
    }
    pacote->tipo = type;
    pacote->tam = numElem;
    pacote->soma = 0;
    pacote->vetor = malloc(numElem * sizeof(type));
    return pacote;
}

void DestroiPacote(tPacote* pac){
    if(pac != NULL){
        free(pac->vetor);
        free(pac);
    }
}

void LePacote(tPacote* pac){
    scanf("%*c");
    printf("\nDigite o conteúdo do vetor/mensagem: ");
        if(pac->tipo == INT){
            for(int i=0; i < pac->tam; i++){
                scanf("%d", (int*)pac->vetor + i);
            }
        }
        else if(pac->tipo == CHAR){
            scanf("%[^\n]%*c", pac->vetor);
        }
}

void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d", pac->soma);
        if(pac->tipo == INT){
            for(int i=0; i < pac->tam; i++){
                printf(" %d", ((int*)pac->vetor)[i]);   
            }
        }
        else if(pac->tipo == CHAR){
            printf(" %s", (char*)pac->vetor);
        }
    printf("\n");
}

void CalculaSomaVerificacaoPacote(tPacote* pac){
    for(int i=0; i < pac->tam; i++){
        if(pac->tipo == INT){
            (pac->soma) += ((int*)pac->vetor)[i];
        }
        else if(pac->tipo == CHAR){
            (pac->soma) += ((char*)pac->vetor)[i];
        }
    }
}