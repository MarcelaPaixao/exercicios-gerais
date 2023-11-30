#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "conta.h"
#include "vector.h"

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia {
    int num;
    char *nome;
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia *agencia = malloc(sizeof(tAgencia));
    if(agencia == NULL){
        printf("Falha na alocacao!\n");
        exit(1);
    }
    agencia->nome = NULL;
    agencia->num = 0;
    agencia->contas = VectorConstruct();
    return agencia;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    if(agencia != NULL){
        tAgencia *A = agencia;
        VectorDestroy(A->contas, DestroiConta);
        free(A->nome);
        free(A);
    }
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    int tam = 0;
    char c = '\0';

    scanf("%d;", &agencia->num);

    while(scanf("%c", &c) == 1 && c != '\n'){
        tam++;
        agencia->nome = realloc(agencia->nome, tam * sizeof(char));
        agencia->nome[tam - 1] = c;
    }
    agencia->nome = realloc(agencia->nome, tam+1);
    agencia->nome[tam] = '\0';
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    return(agencia2->num == numAgencia);
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    float somat=0;
    int qtdTotal=VectorSize(agencia);
    for(int i=0; i < qtdTotal; i++){
        somat += GetSaldoConta(VectorGet(agencia->contas, i));
    }
    return(somat/qtdTotal);
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->num);
    printf("\tNumero de contas cadastradas: %d\n", VectorSize(agencia));
    printf("\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}
