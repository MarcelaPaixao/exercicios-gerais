#include "data.h"
#include <stdio.h>

int main() {
    int dia = 0, mes = 0, ano = 0;

    scanf("%d/%d/%d", &dia, &mes, &ano);

    if (!verificaDataValida(dia, mes, ano)) {
        printf("A data informada eh invalida\n");
        return 0;
    }
    else {
        printf("Data informada: ");
        imprimeDataExtenso(dia, mes, ano);

        if(verificaBissexto(ano)){
            printf("O ano informado eh bissexto\n");
        }
        else {
            printf("O ano informado nao eh bissexto\n");
        }
    
        printf("O mes informado possui %02d dias\n", numeroDiasMes(mes, ano));

        printf("A data seguinte eh: ");
        imprimeProximaData(dia, mes, ano);
    }
    return 0;
}