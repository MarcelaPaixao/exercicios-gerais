#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

int SomaElementosVetor(int n1, int n2){
    return n1 + n2;
}

int ProdutoElementosVetor(int n1, int n2){
    return n1*n2;
}

int main(){
    Vetor vet;

    LeVetor(&vet);
    
    printf("Soma: %d\n", AplicarOperacaoVetor(&vet, SomaElementosVetor));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vet, ProdutoElementosVetor));

    return 0;
}