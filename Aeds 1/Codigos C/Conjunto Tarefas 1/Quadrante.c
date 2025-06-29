#include <stdio.h>
#include <math.h>

int main() {

    float x, y;

    scanf("%f", &x);
    scanf("%f", &y);

    if (x >= 0 && y >= 0){
        printf("primeiro");
    }
    else if (x < 0 && y >= 0){
        printf("segundo");
    }
    else if (x < 0 && y < 0){
        printf("terceiro");
    }
    else{
        printf("quarto");
    }

}




