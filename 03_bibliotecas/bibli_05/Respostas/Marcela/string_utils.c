#include "string_utils.h"
#include <stdio.h>

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str){
    int i=0;
    while(str[i]){
        i++;
    }
    return i;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest){
    int i=0;
    while(src[i]){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str){
    int i=0;
    while(str[i]){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] + ('A'-'a');
        }
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str){
    int i=0;
    while(str[i]){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - ('A'-'a');
        }
        i++;
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str){
    int i = 0, length = string_length(str);
    char invertedStr[length];

    while(length){
        invertedStr[i] = str[length-1];
        length--;
        i++;
    }
    invertedStr[i] = '\0';
    string_copy(invertedStr, str);
}
