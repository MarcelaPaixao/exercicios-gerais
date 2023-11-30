#include <stdio.h>
#include <stdlib.h>
#include "agencia.h"
#include "banco.h"
#include "vector.h"
#include "conta.h"

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco {
    Vector *agencias;
    char *nome;
    int qtdAgencias;
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco(){
    tBanco *banco = malloc(sizeof(tBanco));
    if(banco == NULL){
        printf("Falha na alocacao!\n");
        exit(1);
    }
    banco->qtdAgencias = 0;
    banco->agencias = VectorConstruct();
    banco->nome = NULL;
    return banco;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    if(banco != NULL){
        VectorDestroy(banco->agencias, DestroiAgencia);
        free(banco->nome);
        free(banco);
    }
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco){
    int tam=0;
    char c='\0';
    while(scanf("%c", &c) == 1 && c != '\n'){
        tam++;
        banco->nome = realloc(banco->nome, tam * sizeof(char));
        banco->nome[tam - 1] = c;
    }
    banco->nome = realloc(banco->nome, tam+1);
    banco->nome[tam] = '\0';
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    VectorPushBack(banco->agencias, agencia);
    (banco->qtdAgencias)++;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    for(int i=0; i < banco->qtdAgencias; i++){
        if(ComparaAgencia(numAgencia, VectorGet(banco->agencias, i))){
            AdicionaConta(VectorGet(banco->agencias, i), cliente);
            break;
        }
    }
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    for(int i=0; i < banco->qtdAgencias; i++){
        ImprimeDadosAgencia(VectorGet(banco->agencias, i));
        printf("\n");
    }
}
