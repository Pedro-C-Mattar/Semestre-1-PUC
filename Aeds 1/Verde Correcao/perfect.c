#include <stdio.h>

int ehPerfeito(int num) {
    if (num <= 1) {
        return 0;
    }

    int soma = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            soma += i;
            if (i != num / i) {
                soma += num / i;
            }
        }
    }
    return soma == num;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int X;
        scanf("%d", &X);

        if (ehPerfeito(X)) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d nao eh perfeito\n", X);
        }
    }

    return 0;
}
