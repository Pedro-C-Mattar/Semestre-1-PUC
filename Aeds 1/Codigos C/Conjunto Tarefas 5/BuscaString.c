#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int N;
    char palavra_alvo[500];
    char string_atual[500];
    int count = 0;

    scanf("%d", &N);
    getchar();

    fgets(palavra_alvo, 500, stdin);

    palavra_alvo[strcspn(palavra_alvo, "\n")] = '\0';

    for (int i = 0; palavra_alvo[i]; i++) {
        palavra_alvo[i] = tolower(palavra_alvo[i]);
    }

    for (int i = 0; i < N; i++) {
        fgets(string_atual, 500, stdin);

        int encontrou = 0;
        int pos = 0;
        int len = strlen(string_atual);
        int alvo_len = strlen(palavra_alvo);

        while (pos < len && !encontrou) {

            while (pos < len && isspace(string_atual[pos])) {
                pos++;
            }

            int inicio = pos;

            while (pos < len && !isspace(string_atual[pos])) {
                pos++;
            }

            if (pos - inicio == alvo_len) {
                int match = 1;

                for (int j = 0; j < alvo_len; j++) {
                    if (tolower(string_atual[inicio + j]) != palavra_alvo[j]) {
                        match = 0;
                    }
                }
                if (match) {
                    encontrou = 1;
                }
            }
        }

        if (encontrou) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
