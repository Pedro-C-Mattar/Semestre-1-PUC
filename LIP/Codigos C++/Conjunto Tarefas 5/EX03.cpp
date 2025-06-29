#include <iostream>
#include <vector>
#include <memory>

// Pedro Mattar

using namespace std;

class Animal {
public:
    virtual void fazerSom() = 0;

    void imprimirSom() {
        fazerSom();
    }

    virtual ~Animal() {}
};

class Cachorro : public Animal {
public:
    void fazerSom() override {
        cout << "O cachorro faz: Au Au!" << endl;
    }
};

class Gato : public Animal {
public:
    void fazerSom() override {
        cout << "O gato faz: Miau!" << endl;
    }
};

void emitirSons(const vector<Animal*>& animais) {
    cout << "Emitindo sons dos animais:" << endl;
    for (Animal* animal : animais) {
        animal->imprimirSom();
    }
}

int main() {
    vector<Animal*> animais;
    int opcao;

    do {
        cin >> opcao;

        switch(opcao) {
            case 1:
                animais.push_back(new Cachorro());
                break;
            case 2:
                animais.push_back(new Gato());
                break;
            case 3:
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 3);

    emitirSons(animais);

    for (Animal* animal : animais) {
        delete animal;
    }

    return 0;
}
