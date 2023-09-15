#include "data.h"
#include <stdio.h>

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano){
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data){
    switch(data.mes){
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
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data){
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data){
     if (!(data.ano%400) || !(data.ano%4)){
        return 1;
    }
    if (!(data.ano%100)){
        return 0;
    }
    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data){
    if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11){
        return 30;
    }
    else if(data.mes == 2){
        if(VerificaBissexto(data)){
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
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data){
    if(data.dia < 1 || data.dia > 31 || 
       data.mes < 1 || data.mes > 12 || 
       data.ano < 1){
        return 0;
    }
    else if(data.dia > NumeroDiasMes(data)){
        return 0;
    }
    else {
        return 1;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 */
int ComparaData(tData data1, tData data2){
    if(data1.ano > data2.ano){
        return 1;
    }
    else if(data1.ano < data2.ano){
        return -1;
    }
    else {
        if(data1.mes > data2.mes){
            return 1;
        }
        else if(data1.mes < data2.mes){
            return -1;
        }
        else {
            if(data1.dia > data2.dia){
                return 1;
            }
            else if(data1.dia < data2.dia){
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data){
    int qtdDias=0, mesOriginal=0;
    mesOriginal = data.mes;
    for(int i = data.mes; i > 0; i--){
        data.mes = i;
        qtdDias += NumeroDiasMes(data);
    }
    data.mes = mesOriginal;
    return qtdDias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2){ //AJEITAR A FUNÇÃO PARA MANDAR P OUTRAS FUNÇÕES APENAS O TIPO DATA, E NÃO I, OU SLA
    int ordem=0, qtdDias=0, i, difDias=0;
    
    ordem = ComparaData(data1, data2);
    
    //Caso as datas sejam iguais retornar diferença de 0 dias
    if(ordem == 0){
        return 0;
    }
    
      //Caso a 1 data seja menor
    else if(ordem < 0){
        for(i = data1.ano; i < data2.ano; i++){
            qtdDias += CalculaDiasAteMes(12, i);
        }
        for(i = data1.mes; i < data2.mes; i++){
            qtdDias += NumeroDiasMes(i, data2.ano);
        }
        difDias = data2.dia - data1.dia;
    }
   
      //Caso a 2 data seja maior
    else if(ordem > 0){
        for(i = data2.ano; i < data1.ano; i++){
            qtdDias += CalculaDiasAteMes(12, i);
        }
        for(i = data2.mes; i < data1.mes; i++){
            qtdDias += NumeroDiasMes(i, data1.ano);
        } 
        difDias = data1.dia - data2.dia;
    }
    
  return qtdDias + difDias;
}

