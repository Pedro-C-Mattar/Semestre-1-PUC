#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nomeCompleto[100];
    char sobrenome[50];
    char iniciais[50] = "";
    int i, j = 0, ultimoEspaco = 0;

    fgets(nomeCompleto, sizeof(nomeCompleto), stdin);

    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

    for (i = 0; nomeCompleto[i] != '\0'; i++) {
        if (nomeCompleto[i] == ' ') {
            ultimoEspaco = i;
        }
    }

    strcpy(sobrenome, &nomeCompleto[ultimoEspaco + 1]);

    for (i = 0; i < ultimoEspaco; i++) {
        if (i == 0 || nomeCompleto[i - 1] == ' ') {
            iniciais[j++] = toupper(nomeCompleto[i]);
            iniciais[j++] = '.';
            iniciais[j++] = ' ';
        }
    }
    iniciais[j] = '\0';

    printf("%s, %s\n", sobrenome, iniciais);

    return 0;
}
