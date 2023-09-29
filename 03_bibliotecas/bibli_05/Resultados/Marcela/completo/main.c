#include "string_utils.h"
#include <stdio.h>

int main(){
    char str[501], strCopy[501];
    int option=0;

    scanf("%[^\n]%*c", str);

    while(option != 6){
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");

        scanf("%d", &option);
        printf("Opcao escolhida: \n");
        if(option == 1){
            printf("Tamanho da string: %d\n\n", string_length(str)+1);
        }
        else if(option == 2){
            string_copy(str, strCopy);
            printf("String copiada: %s\n\n", strCopy);
        }
        else if(option == 3){
            string_upper(str);
            printf("String convertida para maiusculas: %s\n\n",str);
        }
        else if(option == 4){
            string_lower(str);
            printf("String convertida para minusculas: %s\n\n",str);
        }
        else if(option == 5){
            string_reverse(str);
            printf("String invertida: \n%s\n\n",str);
        }   
    }

    return 0;
}
