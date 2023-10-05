#include "departamento.h"
#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * @brief Cria um departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 * @return tDepartamento Departamento criado a partir dos valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 */
tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento departamento;
    strcpy(departamento.c1, c1);
    strcpy(departamento.c2, c2);
    strcpy(departamento.c3, c3);
    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    departamento.media_geral = calculaMediaGeralDepartamento(departamento);
    return departamento;
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int validaMediaDepartamento (int media){
    if(media < 0 || media > 10){
        return 0;
    }
    else {
        return 1;
    }
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double calculaMediaGeralDepartamento(tDepartamento depto){
    return (depto.m1 + depto.m2 + depto.m3)/3.0;
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void imprimeAtributosDepartamento (tDepartamento depto){
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2f\n\n", calculaDesvioPadraoDepartamento(depto));
}


/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto){ 
    double dp;
    dp = pow(depto.m1 - depto.media_geral, 2);
    dp += pow(depto.m2 - depto.media_geral, 2);
    dp += pow(depto.m3 - depto.media_geral, 2);
    return sqrt(dp/3.0);
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param deptos Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    tDepartamento auxDepto;
    for(int i = 0; i < tamanho-1; i++){
        for(int j = i+1; j < tamanho; j++){
            if(d[j].media_geral > d[i].media_geral){
                auxDepto = d[i];
                d[i] = d[j];
                d[j] = auxDepto;
            }
        }
    }
}
