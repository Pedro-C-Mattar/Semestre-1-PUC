#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char strings[N][100];
    for (int i = 0; i < N; i++) {
        fgets(strings[i], 100, stdin);
        for (int j = 0; strings[i][j] != '\0'; j++) {
            if (strings[i][j] == '\n') {
                strings[i][j] = '\0';
            }
        }
    }


    char maior_comprimento[100] = "";
    for (int i = 0; i < N; i++) {
        if (strlen(strings[i]) > strlen(maior_comprimento)) {
            strcpy(maior_comprimento, strings[i]);
        }
    }


    char maior_lexico[100] = "";
    strcpy(maior_lexico, strings[0]);
    for (int i = 1; i < N; i++) {
        if (strcmp(strings[i], maior_lexico) > 0) {
            strcpy(maior_lexico, strings[i]);
        }
    }

    printf("%s\n", maior_comprimento);
    printf("%s\n", maior_lexico);

    return 0;
}
