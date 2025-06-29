#include <iostream>
#include <string>
#include <limits>

// Pedro Mattar

using namespace std;

class Carro {
private:
    string marca;
    int ano;

public:
    Carro(string marca, int ano) {
        this->marca = marca;
        this->ano = ano;
    }

    string getMarca() {
        return marca;
    }

    int getAno() {
        return ano;
    }

    void setMarca(string novaMarca) {
        marca = novaMarca;
    }

    void setAno(int novoAno) {
        ano = novoAno;
    }
};

int main() {
    string marcaInicial;
    int anoInicial;

    getline(cin, marcaInicial);
    cin >> anoInicial;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Carro carro(marcaInicial, anoInicial);

    cout << "Detalhes iniciais do carro:" << endl;
    cout << "Marca: " << carro.getMarca() << endl;
    cout << "Ano: " << carro.getAno() << endl;

    string novaMarca;
    getline(cin, novaMarca);
    carro.setMarca(novaMarca);

    carro.setAno(carro.getAno() + 1);

    cout << "Detalhes modificados do carro:" << endl;
    cout << "Marca: " << carro.getMarca() << endl;
    cout << "Ano: " << carro.getAno() << endl;

    return 0;
}
