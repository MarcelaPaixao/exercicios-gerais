#include "esfera_utils.h"
#include <stdio.h>

int main(){
    float R=0;
    scanf("%f", &R);
    printf("Area: %.2f\nVolume: %.2f\n", calcula_area(R), calcula_volume(R));
    return 0;
}
