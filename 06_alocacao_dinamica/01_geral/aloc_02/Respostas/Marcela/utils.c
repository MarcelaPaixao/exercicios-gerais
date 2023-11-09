#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/**
 * Função que cria uma matriz de inteiros, alocada dinamicamente. Se a alocação falhar, o programa é encerrado.
 * 
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz. 
 * @return Ponteiro para a matriz alocada.
*/
int **CriaMatriz(int linhas, int colunas){
    int **mat = malloc(linhas * sizeof(int *));

    for(int i=0; i < linhas; i++){
        mat[i] = malloc(colunas * sizeof(int));
    }

    return mat;
}

/**
 * Função que libera a memória alocada para uma matriz de inteiros.
 * 
 * @param matriz Ponteiro para a matriz a ser liberada.
 * @param linhas Número de linhas da matriz.
*/
void LiberaMatriz(int **matriz, int linhas){
    if(matriz != NULL){
        for(int i=0; i < linhas; i++){
            free(matriz[i]);
        }
        free(matriz);
    }
}

/**
 * Função que lê uma matriz de inteiros da entrada padrão.
 * 
 * @param matriz Ponteiro para a matriz a ser lida.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void LeMatriz(int **matriz, int linhas, int colunas){
    for(int i=0; i < linhas; i++){
        for(int j=0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

/**
 * Imprime a matriz transposta da matriz dada.
 * 
 * @param matriz Ponteiro para a matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    for(int i=0; i < linhas; i++){
        for(int j=0; j < colunas; j++){
            printf("%d", &matriz[j][i]);
        }
        
    }
}

