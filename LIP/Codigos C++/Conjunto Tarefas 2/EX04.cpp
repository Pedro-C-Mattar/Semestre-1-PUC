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
    static int contador;

public:

    Produto() {
        getline(cin, nome);
        cin >> preco;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        contador++;
        cout << "Produto criado: " << nome << endl;
        cout << fixed << setprecision(2);
        cout << "Preco: " << preco << endl;
        cout << "Total de produtos: " << contador << endl;
    }

    Produto(string n, float p) : nome(n), preco(p) {
        contador++;
        cout << "Produto criado: " << nome << endl;
        cout << fixed << setprecision(2);
        cout << "Preco: " << preco << endl;
        cout << "Total de produtos: " << contador << endl;
    }

    ~Produto() {
        contador--;
        cout << "Produto destruido: " << nome << endl;
        cout << "Total de produtos: " << contador << endl;
    }
};

int Produto::contador = 0;

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
