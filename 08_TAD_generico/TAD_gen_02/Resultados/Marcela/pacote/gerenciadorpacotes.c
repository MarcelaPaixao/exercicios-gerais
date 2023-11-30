#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct gerenciadorpacotes {
    int qtdPac;
    tPacote **pacotes;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador *g = malloc(sizeof(tGerenciador));
    if(g == NULL){
        exit(1);
    }
    g->qtdPac = 0;
    g->pacotes = malloc(sizeof(tPacote *));
    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    (geren->qtdPac)++;
    geren->pacotes = realloc(geren->pacotes, geren->qtdPac * sizeof(tPacote *));
    geren->pacotes[geren->qtdPac - 1] = pac;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    if(geren != NULL){
        for(int i=0; i < geren->qtdPac; i++){
            DestroiPacote(geren->pacotes[i]);
        }
        free(geren->pacotes);
        free(geren);
    }
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i=0; i < geren->qtdPac; i++){
        ImprimirPacoteNoIndice(geren, i);
    }
}
