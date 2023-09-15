#include "matrix_utils.h"
#include <stdio.h>

int main(){
    int option=0, rows1=0, cols1=0, rows2=0, cols2=0;
    tMatrix matrix1, matrix2, result;
    
    scanf("%d %d", &rows1, &cols1);
    matrix1 = MatrixCreate(rows1, cols1);
    matrix1 = MatrixRead(matrix1);
    
    scanf("%d %d", &rows2, &cols2);
    matrix2 = MatrixCreate(rows2, cols2);
    matrix2 = MatrixRead(matrix2);
    
    while(option != 6){
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");

        scanf("%d", &option);
        printf("Opcao escolhida: \n");
            
        if(option == 1){
            if(PossibleMatrixSum(matrix1, matrix2)){
                MatrixPrint(MatrixAdd(matrix1, matrix2));
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
            
        else if(option == 2){
            if(PossibleMatrixSub(matrix1, matrix2)){
                MatrixPrint(MatrixSub(matrix1, matrix2));
            }
            else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }
            
        else if(option == 3){
            if(PossibleMatrixMultiply(matrix1, matrix2)){
                MatrixPrint(MatrixMultiply(matrix1, matrix2));
            }
            else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }
            
        else if(option == 4){
            int scalar=0, whichMatriz=0;
            scanf("%d", &scalar);
            scanf("%d", &whichMatriz);
            if(whichMatriz == 1){
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(matrix1);
            }
            else if(whichMatriz == 2){
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(matrix2);
            }
        } 
        else if(option == 5){   
            result = TransposeMatrix(matrix1);
            MatrixPrint(result);
            result = TransposeMatrix(matrix2);
            MatrixPrint(result);
        }
    }
    return 0;    
}