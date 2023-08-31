#include <stdio.h>

int main(){
    int N=0, tamInicial=0, tamFinal=0, i=0, aux=0;

    scanf("%d", &N);
    aux = N;
    while(aux){
        aux = aux/10;
        tamInicial++;
    }

    int resto[tamInicial];
    int num = N;
    while(N >= 9){
        resto[i] =  N % 8;
        N = N/8; 
        tamFinal++;
        if(N <= 9){
            i++;
            resto[i] = N;
            tamFinal++;
        }
        i++;
    }

    for(i = tamFinal-1; i >= 0; i--){
        printf("%d",resto[i]);
    }
    if(!tamFinal){
        printf("%d", num);
    }
    return 0;
}
