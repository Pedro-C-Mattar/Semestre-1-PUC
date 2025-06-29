#include <stdio.h>
#include <math.h>

int main() {

    float segmento1, segmento2, segmento3;

    scanf("%f", &segmento1);
    scanf("%f", &segmento2);
    scanf("%f", &segmento3);

    if((segmento1 + segmento2) < segmento3 || (segmento1 + segmento3) < segmento2 || (segmento2 + segmento3) < segmento1){
        printf("Triangulo invalido");
    }

    else if(segmento1 == segmento2 && segmento2 == segmento3 && segmento1 == segmento3){
        printf("Triangulo equilatero");
    }
    else if(segmento1 == segmento2 || segmento2 == segmento3 || segmento1 == segmento3){
        printf("Triangulo isoceles");
    }
    else{
        printf("Triangulo escaleno");
    }

}



