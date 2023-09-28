#include "loja.h"
#include "vendedor.h"
#include <stdio.h>
#include <string.h>

int main(){
    int qtdLojas=0, option=-1, i, idLoja=0, idxLoja=0;
    float aluguel=0.0, venda=0.0, salario=0.0, prct=0.0; 
    char nomeVendedor[50];

    scanf("%d", &qtdLojas);
    tLoja lojas[qtdLojas];
    tVendedor vendedor;

    while(option != 0){
        scanf("%d", &option);
        scanf("%*c");
        
        //Abrir loja
        if(option == 1){
            scanf("%d %f", &idLoja, &aluguel);
            lojas[idxLoja] = AbreLoja(idLoja, aluguel);
            idxLoja++;
            scanf("%*c");
        }
        //Contratar vendedor
        else if(option == 2){
            scanf("%[^ ]%f %f", nomeVendedor, &salario, &prct);
            scanf("%d", &idLoja);
            scanf("%*c");
            for(i = 0; i < qtdLojas; i++){
                if(VerificaIdLoja(lojas[i], idLoja)){
                    vendedor = RegistraVendedor(nomeVendedor, salario, prct);
                    lojas[i] = ContrataVendedor(lojas[i], vendedor);
                    break;
                }
            }
        }
        //Registrar venda
        else if(option == 3){
            scanf("%d %s", &idLoja, nomeVendedor);
            scanf("%*c");
            scanf("%f", &venda);
            for(i = 0; i < qtdLojas; i++){
                if(VerificaIdLoja(lojas[i], idLoja)){
                    lojas[i] = RegistraVenda(lojas[i], nomeVendedor, venda);
                    break;
                }
            }    
        }
        //Relatório geral
        else if(option == 4){
            for(i = 0; i < qtdLojas; i++){
                ImprimeRelatorioLoja(lojas[i]);
            } 
        }
        //Sair
        else {
            if(option != 0){
                printf("Operacao invalida!\n");
        }
        break;
        }
    }
    return 0;
}