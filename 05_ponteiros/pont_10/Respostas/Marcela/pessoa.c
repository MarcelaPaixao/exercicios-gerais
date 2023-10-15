#include "pessoa.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa){
    scanf("\n%[^\n]", pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai != NULL ||
       pessoa->mae != NULL){
        return 1;
    }
    return 0;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa){
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        
        printf("PAI: ");
        if(pessoa->pai != NULL){
            printf("%s\n", pessoa->pai->nome);
        }
        else {
            printf("NAO INFORMADO\n");
        }
        
        printf("MAE: ");
        if(pessoa->mae != NULL){
            printf("%s\n", pessoa->mae->nome);
        }
        else {
            printf("NAO INFORMADO\n");
        }

        printf("IRMAO: ");
        if(pessoa->irmao != NULL){
            printf("%s\n", pessoa->irmao->nome);
        }
        else {
            printf("NAO INFORMADO\n");
        }
        printf("\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(pessoa1->pai == pessoa2->pai &&
       pessoa1->mae == pessoa2->mae){
        return 1;
    }
    return 0;
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Vetor de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int qtd=0, mae=0, pai=0, filho=0, i, j;

    scanf("%d%*c", &qtd);

    for(i = 0; i < qtd; i++){
        scanf("mae: %d, pai: %d, filho: %d%*c", &mae, &pai, &filho);
        if(mae != -1){
            pessoas[filho].mae = &pessoas[mae];
        }
        if(pai != -1){
            pessoas[filho].pai = &pessoas[pai];
        }
    }
    for(i = 0; i < numPessoas; i++){
        for(j = 0; j < numPessoas; j++){
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) && i != j){
                pessoas[i].irmao = &pessoas[j];
            }
        }
    }
}
