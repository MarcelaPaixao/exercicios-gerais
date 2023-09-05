#include "matrix_utils.h"
#include <stdio.h>

int main(){
    int opcao=0, rows1=0, cols1=0, rows2=0, cols2=0;
    
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);
    
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows1][cols1];
    matrix_read(rows2, cols2, matrix2);
    
    while(opcao != 6){
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");

        scanf("%d", &opcao);
        printf("Opcao escolhida: \n");
            
        if(opcao == 1){
            if(possible_matrix_sum(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, 
                           rows2, cols2, matrix2, 
                           result);
                matrix_print(rows1, cols1, result);
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
            
        else if(opcao == 2){
            if(possible_matrix_sub(rows1, cols1, rows2, cols2)){
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, 
                           rows2, cols2, matrix2, 
                           result);
                matrix_print(rows1, cols1, result);
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
            
        else if(opcao == 3){
            if(possible_matrix_multiply(cols1, rows2)){
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, 
                                rows2, cols2, matrix2, 
                                result);
                matrix_print(rows1, cols2, result);
            }
            else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
            
        else if(opcao == 4){
            int scalar=0, qualMatriz=0;
            scanf("%d", &scalar);
            scanf("%d", &qualMatriz);
            if(qualMatriz == 1){
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else if(qualMatriz == 2){
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }
            
        else if(opcao == 5){
            int result1[cols1][rows1];
            transpose_matrix(rows1, cols1, matrix1, result1);
            matrix_print(cols1, rows1, result1);

            int result2[cols2][rows2];
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(cols2, rows2, result2);
        }
    }
    printf("\n");
    return 0;    
}