#include "matrix_utils.h"
#include <stdio.h>

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix MatrixCreate(int rows, int cols){
    tMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    return matrix;
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix MatrixRead(tMatrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            scanf("%d", &matrix.data[i][j]);
        }
    }
  return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix){
    for(int i = 0; i < matrix.rows; i++){
        printf("|");
        for(int j = 0; j < matrix.cols; j++){
            printf("%d", matrix.data[i][j]);
            if(j != matrix.cols - 1){
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){
        return 1;
    }
    return 0;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols){
        return 1;
    }
    return 0;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    if(matrix1.cols == matrix2.rows){
        return 1;
    }
    return 0;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    result.rows = matrix1.rows;
    result.cols = matrix1.cols;
    
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix1.cols; j++){
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    
    return result;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    result.rows = matrix1.rows;
    result.cols = matrix1.cols;
    
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix1.cols; j++){
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }
    
    return result;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2){
    tMatrix result;
    result.rows = matrix1.rows;
    result.cols = matrix2.cols;
    
    for(int i = 0; i < matrix1.rows; i++){
        for(int j = 0; j < matrix2.cols; j++){
            result.data[i][j] = 0;
            for(int k = 0; k < matrix1.cols; k++){
                result.data[i][j] += (matrix1.data[i][k] * matrix2.data[k][j]);
            }
        }
    }

    return result;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix){
    tMatrix result;
    result.rows = matrix.rows;
    result.cols = matrix.cols;
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            result.data[i][j] = matrix.data[j][i];
        }
    }
    return result;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar){
    for(int i = 0; i < matrix.rows; i++){
        for(int j = 0; j < matrix.cols; j++){
            matrix.data[i][j] *= scalar;
        }
    }
    return matrix;
}
