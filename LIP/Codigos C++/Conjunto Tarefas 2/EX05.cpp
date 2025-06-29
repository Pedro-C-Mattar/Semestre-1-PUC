#include <iostream>
#include <string>
#include <iomanip>
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
        cout << "Produto criado: ";
        getline(cin, nome);
        cin >> preco;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        contador++;
        cout << nome << endl;
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

    Produto(const Produto& outro) {
        nome = "(copia)" + outro.nome;
        preco = outro.preco;
        contador++;
        cout << "Produto criado copia: " << nome << endl;
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
    string nome1;
    float preco1;

    getline(cin, nome1);
    cin >> preco1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Produto p1(nome1, preco1);

    string nome2;
    float preco2;

    getline(cin, nome2);
    cin >> preco2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Produto p2(nome2, preco2);

    Produto p3 = p1;

    return 0;
}
