#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <limits>

//Pedro Mattar

using namespace std;

class Produto {
private:
    string nome;
    float preco;

public:

    Produto() {
        getline(cin, nome);
        cin >> preco;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Produto criado: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
    }

    Produto(string n, float p) : nome(n), preco(p) {
        cout << "Produto criado: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
    }

    ~Produto() {
        cout << "Produto destruido: " << nome << endl;
    }
};

int main() {

    Produto p1;

    string nome;
    float preco;

    getline(cin, nome);
    cin >> preco;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Produto p2(nome, preco);

    return 0;
}
