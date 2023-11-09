#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int tam=0;
    scanf("%d", &tam);
    
    int * vet = CriaVetor(tam);
    LeVetor(vet, tam);
    printf("%.2f", CalculaMedia(vet, tam));

    LiberaVetor(vet);

    return 0;
}