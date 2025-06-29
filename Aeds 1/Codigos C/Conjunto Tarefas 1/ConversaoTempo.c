#include <stdio.h>
#include <math.h>

int main() {

    int segundos, minutos, horas;

    scanf("%d", &segundos);

    horas = segundos / 3600;;

    minutos = (segundos % 3600) / 60;

    segundos = segundos % 60;

    printf("%02d:%02d:%02d", horas, minutos, segundos);

}
