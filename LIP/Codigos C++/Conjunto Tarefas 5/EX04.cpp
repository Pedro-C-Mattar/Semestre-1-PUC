#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Pedro Mattar

using namespace std;

class Veiculo {
protected:
    float velocidade;
public:
    Veiculo() : velocidade(0) {}
    virtual ~Veiculo() {}

    virtual void acelerar(float quantia) = 0;
    virtual void frear(float quantia) = 0;
    virtual string tipo() const = 0;

    void exibirVelocidade(int indice) const {
        cout << "[" << indice << "] Velocidade atual:" << velocidade << " km/h" << endl;
    }

    float getVelocidade() const { return velocidade; }
};

class Carro : public Veiculo {
public:
    void acelerar(float quantia) override {
        velocidade += quantia;
    }

    void frear(float quantia) override {
        velocidade = max(0.0f, velocidade - quantia);
    }

    string tipo() const override {
        return "Carro";
    }
};

class Bicicleta : public Veiculo {
public:
    void acelerar(float quantia) override {
        velocidade += quantia;
    }

    void frear(float quantia) override {
        velocidade = max(0.0f, velocidade - quantia);
    }

    string tipo() const override {
        return "Bicicleta";
    }
};

void exibirTodosVeiculos(const vector<Veiculo*>& veiculos) {
    cout << "Velocidade atual de todos os veiculos:" << endl;
    for (size_t i = 0; i < veiculos.size(); ++i) {
        cout << "Veiculo: " << veiculos[i]->tipo()
             << " [" << i << "] Velocidade atual:"
             << veiculos[i]->getVelocidade() << " km/h" << endl;
    }
}

int main() {
    vector<Veiculo*> veiculos;
    int opcao;

    while (true) {
        cin >> opcao;
        if (opcao == 1) {
            veiculos.push_back(new Carro());
            cout << "Carro adicionado." << endl;
        } else if (opcao == 2) {
            veiculos.push_back(new Bicicleta());
            cout << "Bicicleta adicionada." << endl;
        } else if (opcao == 3) {
            break;
        }
    }

    int indice, operacao;
    float quantia;
    while (true) {
        cin >> indice;
        if (indice == -1) break;

        cin >> operacao;
        cin >> quantia;

        if (indice >= 0 && indice < static_cast<int>(veiculos.size())) {
            if (operacao == 1) {
                veiculos[indice]->acelerar(quantia);
            } else if (operacao == 2) {
                veiculos[indice]->frear(quantia);
            }
            veiculos[indice]->exibirVelocidade(indice);
        }
    }

    exibirTodosVeiculos(veiculos);

    for (auto veiculo : veiculos) {
        delete veiculo;
    }

    return 0;
}
