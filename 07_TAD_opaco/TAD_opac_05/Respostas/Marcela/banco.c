#include "conta.h"
#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

struct Banco{
    tConta **contas;
    int qtd;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco(){
    tBanco *banco = (tBanco *) malloc(sizeof(tBanco));
    if(banco == NULL){
        printf("Falha na alocacao de memoria!\n");
        exit(1);
    }
    banco->contas = malloc(5 * sizeof(tConta *));
    banco->qtd = 0;
    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    if(banco != NULL){
        for(int i=0; i < banco->qtd; i++){
            DestroiConta(banco->contas[i]);
        }
        free(banco->contas);
        free(banco);
    }
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco){
    if(banco->qtd < 5){
        (banco->qtd)++;
        banco->contas[banco->qtd - 1] = CriaConta();
        LeConta(banco->contas[banco->qtd - 1]);
    }
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco){
    int numConta;
    float valor;
    scanf("%d %f", &numConta, &valor);
    for(int i=0; i < banco->qtd; i++){
        if(VerificaConta(banco->contas[i], numConta)){
            SaqueConta(banco->contas[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco){
    int numConta;
    float valor;
    scanf("%d %f", &numConta, &valor);
    for(int i=0; i < banco->qtd; i++){
        if(VerificaConta(banco->contas[i], numConta)){
            DepositoConta(banco->contas[i], valor);
            break;
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco){
    int numOrigem, numDestino, idxOrigem=-1, idxDestino=-1;
    float valor;
    if(banco->contas != NULL){
        scanf("%d %d %f", &numOrigem, &numDestino, &valor);
        for(int i=0; i < banco->qtd; i++){
            if(VerificaConta(banco->contas[i], numOrigem)){
                idxOrigem = i;
            }
            if(VerificaConta(banco->contas[i], numDestino)){
                idxDestino = i;
            }
            if(idxOrigem >= 0 && idxDestino >= 0 && idxOrigem != idxDestino){
                TransferenciaConta(banco->contas[idxDestino], banco->contas[idxOrigem], valor);
                break;
            }
        }
    }
    
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");
    for(int i=0; i < banco->qtd; i++){
        ImprimeConta(banco->contas[i]);
    }
}

