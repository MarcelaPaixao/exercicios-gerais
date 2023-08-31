#include <stdio.h>
#define INDISPONIVEL 1
#define JOGADOR 2
#define ENDGAME 3

int VerificaEndGame(int l, int c, int mat[l][c]){
    int i, j;  
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] == ENDGAME){
               return 1;
            }
        }
    }
    return 0;
}
int VerificaSeEstaVazio(int posicao){
    if(posicao == 0){
        return 1;
    }
    return 0;
}
int ObtemLinhaJog(int l, int c, int mat[l][c]){
    int i, j;  
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] == JOGADOR){
               return i;
            }
        }
    }
    return -1;
}
int ObtemColunaJog(int l, int c, int mat[l][c]){
    int i, j;  
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            if(mat[i][j] == JOGADOR){
               return j;
            }
        }
    }
    return -1;
}
void MoveJogador(int l, int c, int mat[l][c], char * ordem, int xf, int yf){
    int i, j, proxI=0, proxJ=0, lAtual=-1, cAtual=-1, idx=0;

    lAtual = ObtemLinhaJog(l, c, mat);
    cAtual = ObtemColunaJog(l, c, mat);

    while(idx < 4){
        if(ordem[idx] == 'C'){
            proxI = lAtual - 1;
            proxJ = cAtual;
        }
        else if(ordem[idx] == 'B'){
            proxI = lAtual + 1;
            proxJ = cAtual;
        }
        else if(ordem[idx] == 'D'){
            proxI = lAtual;
            proxJ = cAtual + 1;
        }
        else if(ordem[idx] == 'E'){
            proxI = lAtual;
            proxJ = cAtual - 1;
        }
        
        if(proxI >= 0 && proxI < l &&
          proxJ >= 0 && proxJ < c &&
          VerificaSeEstaVazio(mat[proxI][proxJ])){
            mat[lAtual][cAtual] = INDISPONIVEL;
            mat[proxI][proxJ] = JOGADOR;
            printf("(%d,%d) ", proxI+1, proxJ+1);
            if(proxI == xf && proxJ == yf){
                mat[proxI][proxJ] = ENDGAME;
            }
            break;
        }
        else {
            idx++;
        }
    }
    if(idx == 4) {
        mat[lAtual][cAtual] = ENDGAME;
    }
}

int main(){
    int M=0, N=0, xi=0, yi=0, xf=0, yf=0, i, j;
    char prior[4];

    scanf("%d %d", &M, &N);

    int mapa[M][N];
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &mapa[i][j]);
        }
    }
  
    scanf("%d %d", &xi, &yi);
    scanf("%d %d", &xf, &yf);
    scanf("%s", prior);

    mapa[xi-1][yi-1] = JOGADOR;
    printf("(%d,%d) ", xi, yi);

    while(1){
        MoveJogador(M, N, mapa, prior, xf-1, yf-1);
        if(VerificaEndGame(M, N, mapa)){
            break;
        }
    }

    return 0;
}
