#include "temperature_conversor.h"
#include <stdio.h>

int main(){
    float temperature = 0;
    char escala1, escala2;

    scanf("%f %c %c", &temperature, &escala1, &escala2);

    if(escala1 == 'c'){
        if(escala2 == 'k'){
             temperature = convert_temperature(temperature, convert_celsius_to_kelvin);
        }
        else if(escala2 == 'f'){
            temperature = convert_temperature(temperature, convert_celsius_to_fahrenheit);
        }
    }
    else  if(escala1 == 'k'){
        if(escala2 == 'c'){
             temperature = convert_temperature(temperature, convert_kelvin_to_celsius);
        }
        else if(escala2 == 'f'){
            temperature = convert_temperature(temperature, convert_kelvin_to_fahrenheit);
        }
    }
    else  if(escala1 == 'f'){
        if(escala2 == 'c'){
             temperature = convert_temperature(temperature, convert_fahrenheit_to_celsius);
        }
        else if(escala2 == 'k'){
            temperature = convert_temperature(temperature, convert_fahrenheit_to_kelvin);
        }
    }

    printf("Temperature: %.02f%c", temperature, escala2 + 'A'-'a');
    if(escala2 != 'k'){
        printf("º");
    }

    return 0;
}