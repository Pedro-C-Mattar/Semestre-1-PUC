#include <stdio.h>
#include <string.h>

void criptografar(char *frase) {
    int i;
    for (i = 0; frase[i] != '\0'; i++) {
        if (frase[i] >= 'A' && frase[i] <= 'Z') {

            if (frase[i] >= 'X') {
                frase[i] = 'A' + (frase[i] - 'X');
            } else {
                frase[i] += 3;
            }
        } else if (frase[i] == ' ') {

            frase[i] = '#';
        }

    }
}

int main() {
    char frase[100];

    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    criptografar(frase);

    printf("%s", frase);

    return 0;
}
