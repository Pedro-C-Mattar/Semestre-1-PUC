#include <iostream>

// Pedro Mattar

using namespace std;

class Pessoa {
private:
    string nome;
    int idade;

public:
    Pessoa(string n, int i) {
        nome = n;
        idade = i;
    }

    string getNome() {
        return nome;
    }

    int getIdade() {
        return idade;
    }

    void setNome(string n) {
        nome = n;
    }

    void setIdade(int i) {
        idade = i;
    }
};

int main() {
    string nomeInicial, sobrenome;
    int idadeInicial;

    cin >> nomeInicial;
    cin >> idadeInicial;

    Pessoa pessoa(nomeInicial, idadeInicial);

    cout << "Dados iniciais da pessoa:" << endl;
    cout << "Nome: " << pessoa.getNome() << endl;
    cout << "Idade: " << pessoa.getIdade() << endl;

    cin >> sobrenome;

    string nomeCompleto = pessoa.getNome() + " " + sobrenome;
    int novaIdade = pessoa.getIdade() + 1;

    pessoa.setNome(nomeCompleto);
    pessoa.setIdade(novaIdade);

    cout << "Dados modificados da pessoa:" << endl;
    cout << "Nome: " << pessoa.getNome() << endl;
    cout << "Idade: " << pessoa.getIdade() << endl;

    return 0;
}
