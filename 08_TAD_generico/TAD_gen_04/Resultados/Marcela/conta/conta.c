#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "vector.h"

/**
 * @brief Estrutura para representar uma conta bancária.
 */
struct Conta {
    int num;
    float saldo;
    char *nome;
};

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta(){
    tConta *conta = malloc(sizeof(tConta));
    if(conta == NULL){
        printf("Falha na alocacao!\n");
        exit(1);
    }
    conta->nome = NULL;
    conta->num = 0;
    conta->saldo = 0;
    return conta;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta){
    if(conta != NULL){
        tConta *c = conta;
        free(c->nome);
        free(c);
    }
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta){
    int tam = 0;
    char c = '\0';

    scanf("%d;", &conta->num);

    while(scanf("%c", &c) == 1 && c != ';'){
        tam++;
        conta->nome = realloc(conta->nome, tam * sizeof(char));
        conta->nome[tam - 1] = c;
    }
    conta->nome = realloc(conta->nome, tam+1);
    conta->nome[tam] = '\0';

    scanf("%f\n", &conta->saldo);
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta){
    return conta->saldo;
}
