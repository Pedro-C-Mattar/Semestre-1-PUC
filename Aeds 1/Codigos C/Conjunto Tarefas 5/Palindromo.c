#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool palindromo(const char* str) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        while (inicio < fim && !isalpha(str[inicio])) {
            inicio++;
        }
        while (inicio < fim && !isalpha(str[fim])) {
            fim--;
        }
        if (inicio < fim && tolower(str[inicio]) != tolower(str[fim])) {
            return false;
        }

        inicio++;
        fim--;
    }
    return true;
}

int main() {
    char linha[100];

    while (fgets(linha, sizeof(linha), stdin)) {
        linha[strcspn(linha, "\n")] = '\0';

        if (palindromo(linha)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
