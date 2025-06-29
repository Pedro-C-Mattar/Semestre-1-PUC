#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char strings[100][100];
    int max_tamanho = 0, indice_tamanho = 0;
    int indice_lexico = 0;

    for (int i = 0; i < N; i++) {
        scanf("%s", strings[i]);

        int tamanho = strlen(strings[i]);
        if (tamanho > max_tamanho) {
            max_tamanho = tamanho;
            indice_tamanho = i;
        }

        if (strcmp(strings[i], strings[indice_lexico]) > 0) {
            indice_lexico = i;
        }
    }

    printf("%s\n", strings[indice_tamanho]);
    printf("%s\n", strings[indice_lexico]);

    return 0;
}
