#include <stdio.h>

void preencher_vetor(float notas[], int N) {
    for (int i = 0; i < N; i++) {
        scanf("%f", &notas[i]);
    }
}

void processar_vetor(float notas[], int N, float *maior, float *menor, float *media) {
    *maior = notas[0];
    *menor = notas[0];
    *media = 0.0;

    for (int i = 0; i < N; i++) {
        if (notas[i] > *maior) {
            *maior = notas[i];
        }
        if (notas[i] < *menor) {
            *menor = notas[i];
        }
        *media += notas[i];
    }

    *media /= N;
}

int main() {
    int N;
    scanf("%d", &N);

    float notas[N];
    preencher_vetor(notas, N);

    float maior, menor, media;
    processar_vetor(notas, N, &maior, &menor, &media);

    printf("%.1f %.1f %.1f\n", maior, menor, media);

    return 0;
}
