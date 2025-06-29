#include <stdio.h>
#include <math.h>

int main() {

    int horaInicio, horaFim, duracao;

    scanf("%d", &horaInicio);
    scanf("%d", &horaFim);

    if(horaInicio < horaFim){
        duracao = horaFim - horaInicio;
    }
    else{
        duracao = abs((horaInicio - 24) - horaFim);
    }


    if(duracao < 1 || duracao > 24){
        printf("Invalido");
    }
    else{
        printf("O JOGO DUROU %d HORA(S)", duracao);
    }

}

