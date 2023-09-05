#include "data.h"
#include <stdio.h>

void imprimeMesExtenso(int mes){
    switch(mes){
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Março");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
        case 11:
            printf("Novembro");
            break;
        case 12:
            printf("Dezembro");
            break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int verificaBissexto(int ano){
    if (!(ano%400)){
        return 1;
    }
    if (!(ano%100)){
        return 0;
    }
    if (!(ano%4)){
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano){
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    else if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 31;
    }
}

int verificaDataValida(int dia, int mes, int ano){
    if(dia < 1 || dia > 31 || mes < 01 || mes > 12 || ano < 1){
        return 0;
    }
    else if(dia > numeroDiasMes(mes, ano)){
        return 0;
    }
    else {
        return 1;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(dia1 == dia2 && 
       mes1 == mes2 &&
       ano1 == ano2){
        return 0;
    }
    else if(ano1 == ano2){
        if(mes1 > mes2){
            return 1;
        } 
        else if(mes1 == mes2){
            if(dia1 > dia2){
                return 1;
            }   
        }
    }
    else {
        return -1;
    }
}

int calculaDiasAteMes(int mes){
    int qtdDiasAteMes=0;
    for(int i=1; i < mes; i++){
        for(int j=1; j < 32; j++){
            qtdDiasAteMes++;
            if(i == 2 && j == 28){
                break;
            }
            if(i ==  4 || i == 6 || i == 9 || i == 11){
                if(j == 30){
                    break;
                }
            }
        }
    }
    return qtdDiasAteMes;
}
//na h de fazer a main, é so mandar na ordem dps de erificar qual data é maior
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int qtdDias=0;

    for(int i = ano1; i <= ano2; i++){
        for(int j = mes1; j <= 12; j++){
            for(int k = dia1; k <= 31; k++){
                qtdDias++;
                if(j == 2){
                    if(verificaBissexto(i)){
                        if(k == 29){
                            break;
                        }
                    }
                    else {
                        if(k == 28){
                            break;
                        }
                    }
                }
                else if(j ==  4 || j == 6 || j == 9 || j == 11){
                    if(k == 30){
                        break;
                    }
                }
                if(i == ano2 && j == mes2 && k == dia2){
                    return qtdDias;
                }
            }
            dia1 = 0;
        }
        mes1 = 0;
    }
    return qtdDias;
}