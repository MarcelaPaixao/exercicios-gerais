#include "pessoa.h"
#include <stdio.h>

int main(){
    int qtdPessoas=0, i=0;

    scanf("%d", &qtdPessoas);
    tPessoa listaPessoas[qtdPessoas];

    for(i=0; i < qtdPessoas; i++){
        listaPessoas[i] = CriaPessoa();
        LePessoa(&listaPessoas[i]);
    }
   
    AssociaFamiliasGruposPessoas(listaPessoas);
    
    for(i=0; i < qtdPessoas; i++){
       ImprimePessoa(&listaPessoas[i]);
    }

    return 0;
}