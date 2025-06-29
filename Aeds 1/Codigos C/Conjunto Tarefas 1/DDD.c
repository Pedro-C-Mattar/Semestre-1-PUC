#include <stdio.h>
#include <math.h>

int main() {

    int ddd;

    scanf("%d", &ddd);

    if(ddd == 11){
        printf("Brasilia");
    }
    else if(ddd == 21){
        printf("Rio de Janeiro");
    }
    else if(ddd == 31){
        printf("Belo Horizonte");
    }
    else if(ddd == 27){
        printf("Vitoria");
    }
    else if(ddd == 35){
        printf("Lavras");
    }
    else if(ddd == 71){
        printf("Salvador");
    }
    else if(ddd == 19){
        printf("Campinas");
    }
    else{
        printf("DDD nao cadastrado");
    }

}

