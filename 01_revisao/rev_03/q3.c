#include <stdio.h>

int EncontraIdxMenorNum(int vet[], int qtd, int a){
    int i=0, menor=0, idx=0;
    menor = vet[a];
    idx = a;
    for(i = a+1; i < qtd; i++){
        if(vet[i] < menor){
            menor = vet[i];
            idx = i;
        }
    }
    return idx;
}

void OrdenaVetor(int vet[], int tam){
    int i=0, idxMenor=0, aux=0;
    for(i = 0; i < tam-1; i++){
        idxMenor = EncontraIdxMenorNum(vet, tam, i+1); 
        if(vet[idxMenor] < vet[i]){
            aux = vet[i];
            vet[i] = vet[idxMenor];
            vet[idxMenor] = aux;
        }
    }
}

int main(){
    int qtdLivros=0, i=0, j=0, faltouAlgum=0;
    scanf("%d", &qtdLivros);  
    int idLivros[qtdLivros];
    
    for(i = 0; i < qtdLivros; i++){
        scanf("%d", &idLivros[i]);
    }
    
    OrdenaVetor(idLivros, qtdLivros);

    for(i = 0; i < qtdLivros; i++){
        int igual = 0;
        for(j = 0; j < qtdLivros; j++){
            if(i != j){
                if(idLivros[i] == idLivros[j]){
                    igual = 1;
                    break;
                }
            }
        }
        if(!(igual)){
            printf("%d ", idLivros[i]);
            faltouAlgum = 1;
        }
    }
    
    if(!(faltouAlgum)){
        printf("NENHUM");
    }

    return 0;
}
