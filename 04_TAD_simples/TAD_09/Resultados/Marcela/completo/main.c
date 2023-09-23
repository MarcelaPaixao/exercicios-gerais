#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main(){
    int qtdEmpresa=0, i=0;

    scanf("%d", &qtdEmpresa);
    tEmpresa empresas[qtdEmpresa];

    for(i = 0; i < qtdEmpresa; i++){
        empresas[i] = leEmpresa();
    }

    for(i = 0; i < qtdEmpresa; i++){
        imprimeEmpresa(empresas[i]); 
    }

    return 0;
}