
#include <stdio.h>
#include <stdlib.h>

void cadastrarRespostas(int n_alunos, int n_questoes, char respostas[][n_questoes]) {
    for (int i = 0; i < n_alunos; i++) {
        for (int j = 0; j < n_questoes; j++) {
            scanf(" %c", &respostas[i][j]);
        }
    }
}

void cadastrarGabarito(int n_questoes, char gabarito[]) {
    for (int i = 0; i < n_questoes; i++) {
        scanf(" %c", &gabarito[i]);
    }
}

int* calcularPontuacao(int n_alunos, int n_questoes, char respostas[][n_questoes], char gabarito[]) {
    int *pontuacoes = (int*)malloc(n_alunos * sizeof(int));

    for (int i = 0; i < n_alunos; i++) {
        pontuacoes[i] = 0;
        for (int j = 0; j < n_questoes; j++) {
            if (respostas[i][j] == gabarito[j]) {
                pontuacoes[i]++;
            }
        }
    }

    return pontuacoes;
}

int main() {
    int n_alunos, n_questoes;
    scanf("%d %d", &n_alunos, &n_questoes);

    char respostas[n_alunos][n_questoes];
    cadastrarRespostas(n_alunos, n_questoes, respostas);

    char gabarito[n_questoes];
    cadastrarGabarito(n_questoes, gabarito);

    int *pontuacoes = calcularPontuacao(n_alunos, n_questoes, respostas, gabarito);

    for (int i = 0; i < n_alunos; i++) {
        printf("%d ", pontuacoes[i]);
    }
    printf("\n");

    free(pontuacoes);

    return 0;
}
