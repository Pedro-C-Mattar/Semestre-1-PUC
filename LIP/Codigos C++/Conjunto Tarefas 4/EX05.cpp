#include <iostream>
#include <string>
#include <limits>

// Pedro Mattar

using namespace std;

class Animal {
protected:
    string nome;

public:
    Animal() : nome("") {}
    Animal(string nome) : nome(nome) {}

    string getNome() const { return nome; }
    void setNome(string novoNome) { nome = novoNome; }

    virtual void imprime() const {
        cout << "Dados do Animal:" << endl;
        cout << "Nome: " << nome << endl;
    }
};

class Cachorro : public Animal {
private:
    string raca;

public:
    Cachorro() : Animal("Duque"), raca("Indefinido") {}
    Cachorro(string nome, string raca) : Animal(nome), raca(raca) {}

    string getRaca() const { return raca; }
    void setRaca(string novaRaca) { raca = novaRaca; }

    void imprime() const override {
        Animal::imprime();
        cout << "Raca: " << raca << endl;
    }
};

void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    string nomeAnimal, nomeCachorro, racaCachorro;

    getline(cin, nomeAnimal);

    Animal animal(nomeAnimal);
    Cachorro cachorro;
    animal.imprime();
    cachorro.imprime();

    getline(cin, nomeCachorro);
    getline(cin, racaCachorro);

    cachorro.setNome(nomeCachorro);
    cachorro.setRaca(racaCachorro);

    cachorro.imprime();

    return 0;
}
