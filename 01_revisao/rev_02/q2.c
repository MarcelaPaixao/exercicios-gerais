#include <stdio.h>

int main(){
    int i=0, j=0, N=0, num=1;
    scanf("%d", &N);

    for(i = 0; i < N; i++){
        for(j = 0; j <= i; j++){ 
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
    return 0;
}