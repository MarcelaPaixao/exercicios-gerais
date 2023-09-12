#include "data.h"
#include <stdio.h>

int main() {
    int dia1 = 0, mes1 = 0, ano1 = 0, dia2 = 0, mes2 = 0, ano2 = 0, ordem = 0, difDias = 0;

    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if (!verificaDataValida(dia1, mes1, ano1) ||
        !verificaDataValida(dia2, mes2, ano2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);

    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    ordem = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    if (ordem < 0) {
        printf("A segunda data eh mais antiga\n");
    }
    if (ordem > 0) {
        printf("A primeira data eh mais antiga\n");
    }
    if (ordem == 0) {
        printf("As datas sao iguais\n");
    }

    difDias = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", difDias);
    
    return 0;
}