#include "usuario.h"
#include "conta.h"
#include <stdio.h>

int main(){
    int qtdContas=0, numConta=0, option=-1, i=0, j=0;
    char nome[20], cpf[15];
    float valor=0;
    
    scanf("%d", &qtdContas);
    
    tConta listaContas[qtdContas];
    tUsuario user;

    while(option != 0){
        scanf("%d", &option);
        if(option == 1){
            scanf("%d %f", &numConta, &valor);
            j = 0;
            while(j < qtdContas){
                if(VerificaConta(listaContas[j], numConta)){
                    break;
                }
                j++;
            }
            listaContas[j] = SaqueConta(listaContas[j], valor);
        }
        if(option == 2){
            scanf("%d %f", &numConta, &valor);
            j = 0;
            while(j < qtdContas){
                if(VerificaConta(listaContas[j], numConta)){
                    break;
                }
                j++;
            }
            listaContas[j] = DepositoConta(listaContas[j], valor);
        }
        if(option == 3){
            scanf("%[^ ]%*c", nome);
            scanf("%[^ ]%*c", cpf);
            scanf("%d%*c", &numConta);
            user = CriaUsuario(nome, cpf);
            listaContas[i] = CriaConta(numConta,user);
            i++;
        }
        if(option == 4){
            printf("===| Imprimindo Relatorio |===\n");
            for(j = 0; j < qtdContas; j++){
                ImprimeConta(listaContas[j]);
                printf("\n");
            }
        }
    }

    return 0;
}