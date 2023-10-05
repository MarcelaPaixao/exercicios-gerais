#include <stdio.h> 
#include "esfera_utils.h" 
#include <math.h>

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param volume Um ponteiro para uma variável float para armazenar o volume calculado.
 */
void CalculaVolume (float R, float *volume){
    *volume = ((4.0 * PI * (pow(R,3)))/3.0);
}

/**
 * @brief Calcula a área de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param area Um ponteiro para uma variável float para armazenar a área calculada.
 */
void CalculaArea (float R, float *area){
    *area = (4.0 * PI * (pow(R,2)));
}
