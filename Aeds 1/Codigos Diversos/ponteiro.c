#include <stdio.h>

void converter(int totalSegundos, int *h, int *m, int *s){
    *h = totalSegundos / 3600;
    *m = (totalSegundos % 3600) / 60;
    *s = (totalSegundos % 3600) % 60;
}

int main() {
    int segundos = 0;
    int minutos = 0;
    int horas = 0;

    scanf("%d", &segundos);

    converter(segundos, &horas, &minutos, &segundos);

    printf("%02d:%02d:%02d", horas, minutos, segundos);
}
