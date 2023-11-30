#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

int main(){
    tGerenciador *gerenciador = CriaGerenciador();
    int op=0, tamMsg=0, tipo=0;
    printf("tad_gen_02\n");
    
    while(1){
        printf("\nEscolha uma opcao:\n");
        printf("\t(1) Cadastrar um novo pacote\n");
        printf("\t(2) Imprimir um pacote específico\n");
        printf("\t(3) Imprimir todos os pacotes e sair\n");
        scanf("%d\n", &op);
        
        if(op == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d", &tipo, &tamMsg);
            Type t;
            if(tipo == 1){
                t = 1;
            }
            else if(tipo == 0){
                t = 2;
            }
            if(tipo != 1 && tipo != 0){
                printf("\nDigite um tipo valido!\n");
            }
            else {
                tPacote *pac = CriaPacote(t, tamMsg);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(gerenciador, pac);
            }
        }
        else if(op == 2){
            int idx;
            scanf("%d\n", &idx);
            ImprimirPacoteNoIndice(gerenciador, idx);
        }
        else if(op == 3){
            ImprimirTodosPacotes(gerenciador);
            break;
        }
        else {
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }
    DestroiGerenciador(gerenciador);
    return 0;
}