#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <iomanip>

//Pedro Mattar

using namespace std;

class Produto {
private:
    string nome;
    float preco;

public:

    Produto() {

        if (cin.peek() == '\n') {
            cin.ignore();
        }

        getline(cin, nome);

        nome.erase(remove(nome.begin(), nome.end(), '\r'), nome.end());
        nome.erase(remove(nome.begin(), nome.end(), '\n'), nome.end());

        cin >> preco;

        cout << fixed << setprecision(2);
        cout << "Produto criado: " << nome << " - Preco: " << preco << endl;
    }

    ~Produto() {
        cout << "Produto destruido: " << nome << endl;
    }
};

int main() {
    Produto p;
    return 0;
}
