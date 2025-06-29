#include <stdio.h>

int main() {
    int N;
    double S = 0.0;

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        S += (2.0 * i - 1) / i;
    }

    printf("%.2lf\n", S);

    return 0;
}
