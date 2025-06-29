#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

// Pedro Mattar

using namespace std;

class Produto {
private:
    string nome;
    float preco;

public:
    Produto(string nome, float preco) {
        this->nome = nome;
        this->preco = preco;
    }

    string getNome() {
        return nome;
    }

    float getPreco() {
        return preco;
    }

    void setNome(string novoNome) {
        nome = novoNome;
    }

    void setPreco(float novoPreco) {
        preco = novoPreco;
    }
};

int main() {

    string nomeInicial;
    float precoInicial;

    getline(cin, nomeInicial);
    cin >> precoInicial;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Produto produto(nomeInicial, precoInicial);

    cout << fixed << setprecision(2);
    cout << "Detalhes iniciais do produto:" << endl;
    cout << "Nome: " << produto.getNome() << endl;
    cout << "Preco: " << produto.getPreco() << endl;

    string novoNome;
    getline(cin, novoNome);
    produto.setNome(novoNome);

    float novoPreco = produto.getPreco() * 1.10;
    produto.setPreco(novoPreco);

    cout << "Detalhes modificados do produto:" << endl;
    cout << "Nome: " << produto.getNome() << endl;
    cout << "Preco: " << produto.getPreco() << endl;

    return 0;
}
