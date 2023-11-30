#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "conta.h"
#include "agencia.h"
#include "banco.h"

int main(){
    tBanco *banco = CriaBanco();
    LeBanco(banco);
    
    char c;
    while(1){
        
        scanf("%c\n", &c);
        
        if(c == 'A'){
            tAgencia *agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }
        else if(c == 'C'){
            tConta *conta = CriaConta();
            LeConta(conta);
            int numAgencia;
            scanf("%d\n", &numAgencia);
            InsereContaBanco(banco, numAgencia, conta);
        }
        else if(c == 'F'){
            ImprimeRelatorioBanco(banco);
            DestroiBanco(banco);
            break;
        }
    }

    return 0;
}