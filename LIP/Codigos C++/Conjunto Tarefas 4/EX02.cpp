#include <iostream>
#include <limits>

// Pedro Mattar

using namespace std;

class Conta {
protected:
    float saldo;

public:
    Conta() : saldo(0) {}

    virtual void depositar(float valor) {
        if (valor > 0) {
            saldo += valor;
        }
    }

    virtual void sacar(float valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
        } else {
            cout << "Saque invalido. Saldo insuficiente ou valor invalido." << endl;
        }
    }

    float getSaldo() const {
        return saldo;
    }

    virtual void exibirSaldo() const {
        cout << "Saldo Atual:" << saldo << endl;
    }
};

class ContaCorrente : public Conta {
private:
    float limite;
    float limiteUtilizado;

public:
    ContaCorrente() : limite(0), limiteUtilizado(0) {}

    void setLimite(float valor) {
        limite = valor;
    }

    void sacar(float valor) override {
        if (valor <= 0) {
            cout << "Saque invalido. Saldo insuficiente e/ou limite excedido." << endl;
            return;
        }

        if (valor <= saldo) {
            saldo -= valor;
        } else {
            float valorRestante = valor - saldo;
            if (valorRestante <= (limite - limiteUtilizado)) {
                saldo = 0;
                limiteUtilizado += valorRestante;
            } else {
                cout << "Saque invalido. Saldo insuficiente e/ou limite excedido." << endl;
            }
        }
    }

    void depositar(float valor) override {
        if (valor > 0) {
            if (limiteUtilizado > 0) {
                if (valor <= limiteUtilizado) {
                    limiteUtilizado -= valor;
                } else {
                    saldo += (valor - limiteUtilizado);
                    limiteUtilizado = 0;
                }
            } else {
                saldo += valor;
            }
        }
    }

    void exibirSaldo() const override {
        cout << "Saldo Atual:" << saldo << " Limite:" << limite
             << " Limite utilizado:" << limiteUtilizado << endl;
    }
};

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void operacoesConta() {
    Conta conta;
    float valorInicial;
    cin >> valorInicial;
    limparBuffer();
    conta.depositar(valorInicial);

    int numOperacoes;
    cin >> numOperacoes;
    limparBuffer();

    for (int i = 0; i < numOperacoes; i++) {
        int operacao;
        cin >> operacao;
        limparBuffer();

        float valor;
        cin >> valor;
        limparBuffer();

        if (operacao == 1) {
            conta.depositar(valor);
        } else if (operacao == 2) {
            conta.sacar(valor);
        }

        conta.exibirSaldo();
    }
}

void operacoesContaCorrente() {
    ContaCorrente conta;
    float saldoInicial, limite;

    cin >> saldoInicial;
    limparBuffer();
    conta.depositar(saldoInicial);

    cin >> limite;
    limparBuffer();
    conta.setLimite(limite);

    int numOperacoes;
    cin >> numOperacoes;
    limparBuffer();

    for (int i = 0; i < numOperacoes; i++) {
        int operacao;
        cin >> operacao;
        limparBuffer();

        float valor;
        cin >> valor;
        limparBuffer();

        if (operacao == 1) {
            conta.depositar(valor);
        } else if (operacao == 2) {
            conta.sacar(valor);
        }

        conta.exibirSaldo();
    }

    cout << "Saldo Atual:" << conta.getSaldo() << endl;
}

int main() {
    operacoesConta();
    operacoesContaCorrente();
    return 0;
}
