#include <iostream>

// Pedro Mattar

using namespace std;

class ContaBancaria {
private:
    string nomeCliente;
    float saldo;

public:
    ContaBancaria(string nome) {
        nomeCliente = nome;
        saldo = 0;
    }

    void setSaldo(float novoSaldo) {
        if (novoSaldo >= 0) {
            saldo = novoSaldo;
        }
    }

    float getSaldo() {
        return saldo;
    }

    void depositar(float valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depositado: " << valor << endl;
        }
    }

    void sacar(float valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Sacado: " << valor << endl;
        } else {
            cout << "Valor de saque invalido ou saldo insuficiente!" << endl;
        }
    }

    void imprimirDados() {
        cout << endl;
        cout << "Dados da conta apos as movimentacoes:" << endl;
        cout << "Nome do Cliente: " << nomeCliente << endl;
        cout << "Saldo Atual: " << saldo << endl;
    }
};

int main() {
    string nome;
    int numMov, opcao;
    float valor;

    getline(cin, nome);
    ContaBancaria conta(nome);

    cin >> numMov;

    for (int i = 0; i < numMov; i++) {
        cin >> opcao;
        if (opcao == 1) {
            cin >> valor;
            conta.depositar(valor);
        } else if (opcao == 2) {
            cin >> valor;
            conta.sacar(valor);
        } else {
            cout << "Opcao invalida!" << endl;
        }
    }

    conta.imprimirDados();

    return 0;
}
