#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "usuario.h"

struct Usuario{
    char *nome;
    int cpf;
};

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario(){
    tUsuario *user = (tUsuario *) malloc (sizeof(tUsuario));
    if(user == NULL){
        printf("Falha na alocacao de memoria!\n");
        exit(0);
    }
    user->nome = NULL;
    user->cpf = 0;
    return user;
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user){
    if(user != NULL){
        free(user->nome);
        free(user);
    }
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user){
    char caractere = '\0';
    int tam=0;

    while(scanf("%c", &caractere) == 1 && caractere != ' '){
        if(caractere != '\n'){
            tam++;
            user->nome = realloc(user->nome, tam);
            user->nome[tam - 1] = caractere;
        }
    }
    user->nome = realloc(user->nome, tam + 1);
    user->nome[tam] = '\0';

    scanf("%d%*c", &user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\n", user->nome);
    printf("CPF: %d\n\n", user->cpf);
}

