#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

int main (){
    char option;
    tBanco * banco = CriaBanco();

    while(1){
        scanf("%c", &option);
        if(option == 'F'){
            DestroiBanco(banco);
            break;
        }
        else  if(option == 'S'){
            SaqueContaBanco(banco);
        }
        else  if(option == 'D'){
            DepositoContaBanco(banco);
        }
        else  if(option == 'T'){
            TransferenciaContaBanco(banco);
        }
        else  if(option == 'A'){
            AbreContaBanco(banco);
        }
        else  if(option == 'R'){
            ImprimeRelatorioBanco(banco);
        }
    }

    return 0;
}