#include "filme.h"
#include "locadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Locadora {
    tFilme **filmes;
    int qtd, lucro;
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora (){
    tLocadora *loc = (tLocadora *) malloc(sizeof(tLocadora));
    if(loc == NULL){
        printf("Falha na alocacao de memoria!\n");
        exit(0);
    }
    loc->filmes = NULL;
    loc->qtd = 0;
    loc->lucro = 0;
    return loc;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora){
    if(locadora != NULL){
        for(int i=0; i < locadora->qtd; i++){
            DestruirFilme(locadora->filmes[i]);
        }
        free(locadora->filmes);
        free(locadora);
    }
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    for(int i=0; i < locadora->qtd; i++){
        if(EhMesmoCodigoFilme(locadora->filmes[i], codigo)){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    if(!VerificarFilmeCadastrado(locadora->filmes, ObterCodigoFilme(filme))){
        (locadora->qtd)++;
        locadora->filmes = realloc(locadora->filmes, locadora->qtd);
        locadora->filmes[locadora->qtd - 1] = CriarFilme();
        locadora->filmes[locadora->qtd - 1] = filme;
    }
    else{
        printf("Filme ja cadastrado no estoque.\n");
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora){
    int codigo=0;
    scanf("%d,", &codigo);
    tFilme *filme = CriarFilme();
    LeFilme(filme, codigo);
    CadastrarFilmeLocadora(Locadora, filme);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i=0; i < quantidadeCodigos; i++){
        for(int j=0; j < locadora->filmes; j++){
            if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])){
                if(ObterQtdEstoqueFilme(locadora->filmes[j])){
                    AlugarFilme(locadora->filmes[j]);
                }
                else {
                    printf("Filme");
                    ImprimirNomeFilme(locadora->filmes[j]);
                    printf("- %d nao  disponivel  no  estoque.  Volte  mais tarde.\n", codigos[i]);  
                }
            }
            
        }
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora){
    int cod, total=0;
    int *codigos = (int *)malloc(sizeof(int));
    //int *codigos = NULL;
    while(scanf("%d\n", &cod) == 1){
        total++;
        codigos = realloc(codigos, total);
        codigos[total - 1] = cod;
    }
    AlugarFilmesLocadora(locadora, codigos, total);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos);

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora){
    int cod, total=0;
    int *codigos = (int *)malloc(sizeof(int));
    //int *codigos = NULL;
    while(scanf("%d\n", &cod) == 1){
        total++;
        codigos = realloc(codigos, total);
        codigos[total - 1] = cod;
    }
    DevolverFilmesLocadora(locadora, codigos, total);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora);

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora){
    return locadora->qtd;
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora){
    return locadora->lucro;
}
