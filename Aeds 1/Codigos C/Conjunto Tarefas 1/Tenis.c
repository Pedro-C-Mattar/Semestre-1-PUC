#include <stdio.h>
#include <math.h>

int main() {

    char resultado1, resultado2, resultado3, resultado4, resultado5, resultado6;
    int vitoria = 0;

    scanf(" %c", &resultado1);
    scanf(" %c", &resultado2);
    scanf(" %c", &resultado3);
    scanf(" %c", &resultado4);
    scanf(" %c", &resultado5);
    scanf(" %c", &resultado6);

    if (resultado1 == 'V'){
        vitoria ++;
    }
    if (resultado2 == 'V'){
        vitoria ++;
    }
    if (resultado3 == 'V'){
        vitoria ++;
    }
    if (resultado4 == 'V'){
        vitoria ++;
    }
    if (resultado5 == 'V'){
        vitoria ++;
    }
    if (resultado6 == 'V'){
        vitoria ++;
    }

    if (vitoria == 5 || vitoria == 6){
        printf("1");
    }
    else if (vitoria == 3 || vitoria == 4){
        printf("2");
    }
    else if (vitoria == 1 || vitoria == 2){
        printf("3");
    }
    else{
        printf("-1");
    }

}


