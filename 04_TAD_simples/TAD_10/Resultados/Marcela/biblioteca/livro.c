#include "livro.h"
#include <stdio.h>

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @return Um livro com os atributos lidos.
 */
tLivros lerLivro(){
    tLivros livro;
    scanf("%[^\n]%*c", livro.titulo);
    scanf("%[^\n]%*c", livro.autor);
    scanf("%d%*c", &livro.anoPublicacao);
    return livro;
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro O livro cujos atributos serão impressos
*/
void imprimeLivro(tLivros livro){
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
}