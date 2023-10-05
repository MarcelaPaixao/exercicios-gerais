#include <stdio.h> 
#include "evento.h" 

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){
    Evento event;
    int qtd = *numEventos;
    if(*numEventos < MAX_EVENTOS){
        scanf("%s", event.nome);
        scanf("%d %d %d", &event.dia, &event.mes, &event.ano);
        eventos[*numEventos] = event;
        qtd++;
        *numEventos = qtd;
        printf("Evento cadastrado com sucesso!\n");
    }
    else {
        printf("Limite de eventos atngido!\n");
    }
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){ 
    if(*numEventos == 0){
        printf("Nenhum evento cadastrado.\n");
    }
    else {
        printf("Eventos cadastrados:\n");
        for(int i = 0; i < *numEventos; i++){
            printf("%d - %s -", i, eventos[i].nome);
            printf("%d/%d/%d\n", eventos[i].dia, eventos[i].mes, eventos[i].ano);
        }
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    int idx = 0;
    scanf("%d", &idx);
    if(idx < *numEventos){
        scanf("%d %d %d", &eventos[idx].dia, &eventos[idx].mes, &eventos[idx].ano);
        printf("Data modificada com sucesso!\n");
    }
    else {
        printf("Indice invalido!\n");
    }
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento event;
    if(*indiceA < *numEventos && *indiceB < *numEventos){
        event = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = event;
        printf("Eventos trocados com sucesso!\n");
    }
    else {
        printf("Indices invalidos!\n");
    }
}



