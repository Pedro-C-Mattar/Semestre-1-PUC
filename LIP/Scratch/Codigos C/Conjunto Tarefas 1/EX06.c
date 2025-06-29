#include <stdio.h>
#include <math.h>

int main(){
    float raio, altura, volume;

    printf("Digite o valor da altura: \n");
    scanf("%f", &altura);
    printf("Digite o valor do raio: \n");
    scanf("%f", &raio);

    volume = (3.14159 * pow(raio, 2) * altura);

    printf("O volume do cilindro:%.3f", volume);
}

