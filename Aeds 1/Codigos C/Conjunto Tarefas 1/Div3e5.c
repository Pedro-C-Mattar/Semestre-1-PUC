#include <stdio.h>
#include <math.h>

int main() {

    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 % 5 == 0 && num1 % 3 == 0){
        printf("Divisível por ambos\n");
    }
    else if(num1 % 3 == 0){
        printf("Divisível por 3\n");
    }
    else if(num1 % 5 == 0){
        printf("Divisível por 5\n");
    }
    else{
        printf("Divisível por nenhum\n");
    }


    if (num2 % 3 == 0 && num2 % 5 == 0){
        printf("Divisível por ambos\n");
    }
    else if(num2 % 3 == 0){
        printf("Divisível por 3\n");
    }
    else if(num2 % 5 == 0){
        printf("Divisível por 5\n");
    }
    else{
        printf("Divisível por nenhum\n");
    }


    if (num3 % 3 == 0 && num3 % 5 == 0){
        printf("Divisível por ambos\n");
    }
    else if(num3 % 3 == 0){
        printf("Divisível por 3\n");
    }
    else if(num3 % 5 == 0){
        printf("Divisível por 5\n");
    }
    else{
        printf("Divisível por nenhum\n");
    }

}
