#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int mensagemOraculo(int anoAtu, int mesAtu, int diaAtu, int anoNas, int mesNas, int diaNas) {
    int idade;

    printf("Estou no procedimento!\n");

    idade = anoAtu - anoNas;

    if (mesAtu < mesNas || (mesAtu == mesNas && diaAtu < diaNas)) {
        idade--;
    }

    printf("saindo do procedimento!\n");

    return idade;
}

int main() {
    int n = 0;
    int i = 0;
    char nome[50];
    int anoAtua = 0;
    int mesAtua = 0;
    int diaAtua = 0;
    int anoNasc = 0;
    int mesNasc = 0;
    int diaNasc = 0;
    int result = 0;

    printf("Digite a data atual no formato dd/mm/aaaa:\n");
    scanf("%d/%d/%d", &diaAtua, &mesAtua, &anoAtua);

    printf("Quantas mensagens deseja enviar?:\n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        printf("conjunto %d:\n", i);
        printf("Digite o nome:\n");
        scanf(" %49[^\n]", nome);
        printf("Digite a data de nascimento formato dd/mm/aaaa:\n");
        scanf("%d/%d/%d", &diaNasc, &mesNasc, &anoNasc);
        printf("Chamando o procedimento!\n");
        result = mensagemOraculo(anoAtua, mesAtua, diaAtua, anoNasc, mesNasc, diaNasc);
        printf("Voltou do procedimento!\n");
        printf("Ola %s! Voce tem %d anos!\n", nome, result);
    }

}
