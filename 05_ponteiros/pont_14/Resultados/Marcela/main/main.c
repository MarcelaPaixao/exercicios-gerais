#include "botao.h"
#include "tela.h"
#include <stdio.h>
#include <stdlib.h>

#define ALTURA 200
#define LARGURA 400

void Botao_0(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void Botao_1(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void Botao_2(){
    printf("- Botao de OPCOES ativado!\n");
}

int main(){
    Tela tela;
    Botao botao;
    tela = CriarTela(ALTURA, LARGURA);
    
    botao = CriarBotao("Salvar", 12, "FFF", 1, Botao_0);
    RegistraBotaoTela(&tela, botao);

    botao = CriarBotao("Excluir", 18, "000", 1, Botao_1);
    RegistraBotaoTela(&tela, botao);

    botao = CriarBotao("Opcoes", 10, "FF0000", 2, Botao_2);
    RegistraBotaoTela(&tela, botao);

    DesenhaTela(tela);
    OuvidorEventosTela(tela);
    
    return 0;
}