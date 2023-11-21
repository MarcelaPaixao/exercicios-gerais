#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main(){
    int tam=0;
    scanf("%d\n", &tam);

    char *vet = CriaVetor(tam);
    ImprimeString(vet, tam);
    
    LeVetor(vet, tam);
    ImprimeString(vet, tam);
    
    LiberaVetor(vet);

    return 0;
}