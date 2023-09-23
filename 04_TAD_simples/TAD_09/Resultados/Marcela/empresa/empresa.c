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
    empresa.qtdFuncionarios = 0;
    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * 
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa(){
    int id=0, qtdFuncionarios=0;
    tFuncionario funcionario;
    
    scanf("%d %d", &id, &qtdFuncionarios);
    
    tEmpresa empresa = criaEmpresa(id);
    
    for(int i = 0; i < qtdFuncionarios; i++){
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
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
        if(getIdFuncionario(empresa.funcionarios[i]) == funcionario.id){
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));
            return empresa;
        }
    }
    empresa.qtdFuncionarios++;
    empresa.funcionarios[empresa.qtdFuncionarios-1] = funcionario;
    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa){ 
    printf("Empresa %d:\n", empresa.id);
    for(int i = 0; i < empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}

