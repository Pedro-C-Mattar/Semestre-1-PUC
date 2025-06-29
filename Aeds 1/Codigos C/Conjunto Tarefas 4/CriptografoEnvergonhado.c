#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int mod(char *K, int p) {
    int res = 0;
    for (int i = 0; K[i] != '\0'; ++i) {
        res = (res * 10 + (K[i] - '0')) % p;
    }
    return res;
}

int main() {
    char K[1010];
    int L;
    while (1) {
        scanf("%s %d", K, &L);

        int stop = (strcmp(K, "0") == 0 && L == 0);
        if (stop) {
            return 0;
        }

        bool found = false;
        int minP = 0;

        for (int p = 2; p < L && !found; ++p) {
            if (primo(p)) {
                found = (mod(K, p) == 0);
                minP = found ? p : minP;
            }
        }

        printf(found ? "BAD %d\n" : "GOOD\n", minP);
    }
    return 0;
}
