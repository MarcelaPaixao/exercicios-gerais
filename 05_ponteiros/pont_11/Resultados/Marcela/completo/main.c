#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>

float soma(float n1, float n2){
    return n1 + n2;
}

float subtracao(float n1, float n2){
    return n1 - n2;
}

float multiplicacao(float n1, float n2){
    return n1 * n2;
}

float divisao(float n1, float n2){
    if(n2 == 0){
        printf("ERRO\n");
        return -1;
    }
    return n1/n2;
}

int  main(){
    char opcao;
    float n1, n2, result=0;

    while(1){
        scanf("%c", &opcao);
        scanf("%f %f", &n1, &n2);    
       
        if(opcao == 'f'){
            break;
        }

        switch (opcao){
            case 'a':
                result = Calcular(n1, n2, soma);
                printf("%.2f + %.2f = %.2f\n", n1, n2, result);
                break;
            case 's':
                result = Calcular(n1, n2, subtracao);
                printf("%.2f - %.2f = %.2f\n", n1, n2, result);
                break;
            case 'm':
                result = Calcular(n1, n2, multiplicacao);
                printf("%.2f x %.2f = %.2f\n", n1, n2, result);
                break;
            case 'd':
                result = Calcular(n1, n2, divisao);
                printf("%.2f / %.2f = %.2f\n", n1, n2, result);
                break;    
        }
    }
    return 0;
}