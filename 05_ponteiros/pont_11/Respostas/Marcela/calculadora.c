#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função que realiza uma operação matemática entre dois númeross.
 * 
 * @param num1 Primeiro número.
 * @param num2 Segundo número.
 * @param operacao Ponteiro para a função que realiza a operação matemática.
 * @return float Resultado da operação matemática.
 */
float Calcular(float num1, float num2, CalculatoraCallback operacao){
    return operacao(num1, num2);
}
