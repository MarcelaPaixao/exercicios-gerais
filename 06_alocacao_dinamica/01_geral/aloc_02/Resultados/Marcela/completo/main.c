#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int lin, col;
    scanf("%d%d", &lin, &col);
    
    int **mat = CriaMatriz(lin, col);
    LeMatriz(mat, lin, col);
    ImprimeMatrizTransposta(mat, lin, col);
    LiberaMatriz(mat, lin);

    return 0;
}