#include "biblioteca.h"
#include "livro.h"
#include <stdio.h>

int main(){
    int N=0, option=0;
    tBiblioteca biblioteca;
    tLivros livro;
    char tituloLivro[50];

    scanf("%d", &N);
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");

    while(N){
        scanf("%d", &option);
        if(option == 1){
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if(option == 2){
            scanf("%s", tituloLivro);
            biblioteca = removerLivroDaBiblioteca(biblioteca, tituloLivro);
        }
        else if(option == 3){

        }
        N--;
    }

    return 0;
}