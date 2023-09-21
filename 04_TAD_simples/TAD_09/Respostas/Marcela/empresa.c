#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

/**
 * @brief Cria uma empresa a partir de um id.
 * 
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id){
    tEmpresa empresa;
    empresa.id = id;
    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    int id=0, qtdFuncionarios=0;
    
    scanf("%d %d", &id, &qtdFuncionarios);
    
    tEmpresa empresa = criaEmpresa(id);
    empresa.qtdFuncionarios = qtdFuncionarios;
    
    for(int i = 0; i < qtdFuncionarios; i++){
        empresa.funcionarios[i] = leFuncionario();
    }
    return empresa;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    for(int i = 0; i < empresa.qtdFuncionarios; i++){
        if(getIdFuncionario(empresa.funcionarios[i]) != funcionario.id){
            empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
        }
        else {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));
            empresa.qtdFuncionarios--;
        }
    }
    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){ //AJUSTAR DE ACORDO COM PDF
    for(int i = 0; i < empresa.qtdFuncionarios; i++){
        empresa = contrataFuncionarioEmpresa(empresa, empresa.funcionarios[i]);
    }
    printf("Empresa %d:\n", empresa.id);
    for(int i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}

