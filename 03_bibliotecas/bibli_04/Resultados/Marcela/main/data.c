#include "data.h"
#include <stdio.h>

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês da data.
 */
void imprimeMesExtenso(int mes){
    switch(mes){
        case 1:
            printf("Janeiro");
            break;
        case 2:
            printf("Fevereiro");
            break;
        case 3:
            printf("Março");
            break;
        case 4:
            printf("Abril");
            break;
        case 5:
            printf("Maio");
            break;
        case 6:
            printf("Junho");
            break;
        case 7:
            printf("Julho");
            break;
        case 8:
            printf("Agosto");
            break;
        case 9:
            printf("Setembro");
            break;
        case 10:
            printf("Outubro");
            break;
        case 11:
            printf("Novembro");
            break;
        case 12:
            printf("Dezembro");
            break;
    }
}

/**
 * @brief Imprime uma data por extenso no formato "DD de NOME_DO_MES de AAAA".
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if (!(ano%400) || !(ano%4)){
        return 1;
    }
    if (!(ano%100)){
        return 0;
    }
    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    else if(mes == 2){
        if(verificaBissexto(ano)){
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
        return 31;
    }
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){
    if(dia < 1 || dia > 31 || 
       mes < 1 || mes > 12 || 
       ano < 1){
        return 0;
    }
    else if(dia > numeroDiasMes(mes, ano)){
        return 0;
    }
    else {
        return 1;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda e 0 se as datas são iguais.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return -1;
    }
    else if(ano1 < ano2){
        return 1;
    }
    else {
        if(mes1 > mes2){
            return -1;
        }
        else if(mes1 < mes2){
            return 1;
        }
        else {
            if(dia1 > dia2){
                return -1;
            }
            else if(dia1 < dia2){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

/**
 * @brief Calcula o número de dias até o início de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @return Retorna o número de dias até o início do mês.
 */
int calculaDiasAteMes(int mes, int ano){
    int qtdDias=0;
    for(int i = mes; i > 0; i--){
        qtdDias += numeroDiasMes(i, ano);
    }
    return qtdDias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int ordem=0, qtdDias=0, i, difDias=0;
    
    ordem = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    
    //Caso as datas sejam iguais retornar diferença de 0 dias
    if(ordem == 0){
        return 0;
    }
    
      //Caso a 1 data seja menor
    else if(ordem > 0){
        for(i = ano1; i < ano2; i++){
            qtdDias += calculaDiasAteMes(12, i);
        }
        for(i = mes1; i < mes2; i++){
            qtdDias += numeroDiasMes(i, ano2);
        }
        difDias = dia2 - dia1;
    }
   
      //Caso a 2 data seja maior
    else if(ordem < 0){
        for(i = ano2; i < ano1; i++){
            qtdDias += calculaDiasAteMes(12, i);
        }
        for(i = mes2; i < mes1; i++){
            qtdDias += numeroDiasMes(i, ano1);
        } 
        difDias = dia1 - dia2;
    }
    
  return qtdDias + difDias;
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano){
    if(dia+1 > numeroDiasMes(mes, ano)){
        dia = 1;
        if(mes+1 > 12){
            mes = 1;
            ano++;
        }
        else {
            mes++;
        }
    }
    else {
        dia++;
    }
    printf("%02d/%02d/%04d\n", dia, mes, ano);
}