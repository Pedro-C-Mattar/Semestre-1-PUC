#include <iostream>
using namespace std;

int main() {
    int N = 0;
    int T = 0;
    int contadorT1 = 0;
    int contadorT2 = 0;
    int P = 0;
    int M = 0;

    cin >> N;

    if (N >= 1 && N <= 1000) {
        for (int i = 1; i <= N; i++) {
            cin >> T;
            if (T == 1 || T == 2) {
                if (T == 1) {
                    contadorT1++;
                }
                if (T == 2) {
                    contadorT2++;
                }
            }
        }
        cin >> P;
        if (P >= 0 && P <= 1000) {
            cin >> M;
            if (M >= 0 && M <= 1000) {
                if (N <= P + M) {
                    if (P >= contadorT1 && M >= contadorT2) {
                        cout << "S";
                    }
                    else {
                        cout << "N";
                    }
                }
            }
        }
    }
    return 0;
}

