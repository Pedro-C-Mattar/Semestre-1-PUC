#include <stdio.h>
#include <math.h>

int main() {

    int diaInicio, diaFim, segInicio, minInicio, hrInicio, segFim, minFim, hrFim, segundos, minutos, horas, dias;

    scanf("%d", &diaInicio);
    scanf("%d %d %d", &hrInicio, &minInicio, &segInicio);
    scanf("%d", &diaFim);
    scanf("%d %d %d", &hrFim, &minFim, &segFim);

    if(diaInicio > 31 || hrInicio >= 24 || minInicio >= 60 || segInicio >= 60){
        printf("Invalido");
    }
    else if(diaFim > 31 || hrFim >= 24 || minFim >= 60 || segFim >= 60){
        printf("Invalido");
    }
    else{
        segInicio = (diaInicio - 1) * 86400 + hrInicio * 3600 + minInicio * 60 + segInicio;
        segFim = (diaFim - 1) * 86400 + hrFim * 3600 + minFim * 60 + segFim;
        segundos = segFim - segInicio;

        dias = segundos / 86400;
        horas = (segundos % 86400) / 3600;
        minutos = ((segundos % 86400) % 3600) / 60;
        segundos = segundos % 60;

        printf("%d dia(s)\n", dias);
        printf("%d hora(s)\n", horas);
        printf("%d minuto(s)\n", minutos);
        printf("%d segundo(s)\n", segundos);
    }

}


