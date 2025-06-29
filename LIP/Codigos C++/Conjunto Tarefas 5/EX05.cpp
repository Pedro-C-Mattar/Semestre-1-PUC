#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

// Pedro Mattar

using namespace std;

class ContaBancaria {
protected:
    double saldo;
    string tipoConta;

public:
    ContaBancaria() : saldo(0.0) {}
    virtual ~ContaBancaria() {}

    virtual void depositar(double valor) = 0;
    virtual void retirar(double valor) = 0;

    void exibirSaldo() const {
        cout << "Tipo de conta: " << tipoConta << "; Saldo atual: R$ "
             << fixed << setprecision(2) << saldo << endl;
    }
};

class ContaCorrente : public ContaBancaria {
public:
    ContaCorrente() {
        tipoConta = "Corrente";
    }

    void depositar(double valor) override {
        saldo += valor;
    }

    void retirar(double valor) override {
        double valorTotal = valor + 1.0;
        if (valorTotal <= saldo) {
            saldo -= valorTotal;
        }
    }
};

class Poupanca : public ContaBancaria {
public:
    Poupanca() {
        tipoConta = "Poupanca";
    }

    void depositar(double valor) override {
        saldo += valor * 1.01;
    }

    void retirar(double valor) override {
        if (valor <= saldo) {
            saldo -= valor;
        }
    }
};

void exibirTodasContas(const vector<ContaBancaria*>& contas) {
    cout << "Saldos e tipos de todas as contas:" << endl;
    for (const auto& conta : contas) {
        conta->exibirSaldo();
    }
}

int main() {
    vector<ContaBancaria*> contas;
    int opcao;

    while (cin >> opcao && opcao != 9) {
        switch (opcao) {
            case 1:
                contas.push_back(new ContaCorrente());
                cout << "Conta Corrente adicionada." << endl;
                break;
            case 2:
                contas.push_back(new Poupanca());
                cout << "Poupanca adicionada." << endl;
                break;
        }
    }

    while (true) {
        int indice;
        if (!(cin >> indice) || indice == 9) break;

        int operacao;
        if (!(cin >> operacao)) break;

        if (operacao == 3) {
            exibirTodasContas(contas);
            continue;
        }

        double valor;
        if (!(cin >> valor)) break;

        if (indice >= 0 && indice < static_cast<int>(contas.size())) {
            if (operacao == 1) {
                contas[indice]->depositar(valor);
            } else if (operacao == 2) {
                contas[indice]->retirar(valor);
            }
            contas[indice]->exibirSaldo();
        }
    }

    exibirTodasContas(contas);

    for (auto& conta : contas) {
        delete conta;
    }

    return 0;
}
