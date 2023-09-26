#include "biblioteca.h"
#include "livro.h"
#include <stdio.h>
#include <string.h>

/**
 * Inicializa uma biblioteca vazia.
 *
 * @return A biblioteca inicializada.
 */
tBiblioteca inicializarBiblioteca(){
    tBiblioteca biblioteca;
    biblioteca.tamanho = 0;
    return biblioteca;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro){
    if(biblioteca.tamanho == MAX_LIVROS){
        printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
    }
    else {
        biblioteca.tamanho++;
        biblioteca.livros[biblioteca.tamanho-1] = livro;
        printf("Livro adicionado com sucesso!\n");
    }
    return biblioteca;
}

/**
 * Remove um livro da biblioteca pelo título. 
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo){
    tLivros livro;
    int encontrado=0;
    for(int i = 0; i < biblioteca.tamanho; i++){
        livro = biblioteca.livros[i];
        if(strcmp(titulo, livro.titulo) == 0){
            encontrado = 1;
            break;
        }
    }
    if(!encontrado){
        printf("Livro não encontrado na biblioteca.\n");
    }
    else if(encontrado){
        printf("Livro removido com sucesso!\n");
        //REMOVER O LIVRO!!!!!!1
    }
    return biblioteca;
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 * 
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
*/
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo){
    return (strcmp(livro.titulo, titulo));
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca A biblioteca cujos livros serão listados.
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca){
    if(biblioteca.tamanho == 0){
        printf("A biblioteca esta vazia!\n");
    }
    else {
        printf("Lista de Livros na Biblioteca:\n");
        for(int i = 0; i < biblioteca.tamanho; i++){
            imprimeLivro(biblioteca.livros[i]);
            printf("\n");
        }
    }
}


