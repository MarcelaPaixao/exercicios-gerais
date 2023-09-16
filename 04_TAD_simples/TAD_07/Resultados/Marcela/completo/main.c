#include "data.h"
#include <stdio.h>

int main() {
    int dia = 0, mes = 0, ano = 0, ordem = 0, difDias = 0;
    tData data1, data2;

    scanf("%d/%d/%d", &dia, &mes, &ano);
    data1 = CriaData(dia, mes, ano);
    scanf("%d/%d/%d", &dia, &mes, &ano);
    data2 = CriaData(dia, mes, ano);

    if (!VerificaDataValida(data1) ||
        !VerificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);

    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    ordem = ComparaData(data1, data2);
    if (ordem < 0) {
        printf("A segunda data eh mais antiga\n");
    }
    if (ordem > 0) {
        printf("A primeira data eh mais antiga\n");
    }
    if (ordem == 0) {
        printf("As datas sao iguais\n");
    }

    difDias = CalculaDiferencaDias(data1, data2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", difDias);
    
    return 0;
}
