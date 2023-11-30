#include <stdio.h>
#include "tadgen.h"

int main(){
    int qtd, tipo;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d%d", &tipo, &qtd);
    tGeneric *generic = CriaGenerico(tipo, qtd);
    LeGenerico(generic);
    ImprimeGenerico(generic);
    DestroiGenerico(generic);
    return 0;
}