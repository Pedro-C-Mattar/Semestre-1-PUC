#include <iostream>
#include <vector>
#include <iomanip>

// Pedro Mattar

using namespace std;

class Funcionario {
public:
    virtual double calcularSalario() = 0;

    void imprimirSalario() {
        cout << fixed << setprecision(2);
        cout << "Salario: " << calcularSalario() << endl;
    }

    virtual ~Funcionario() {}
};

class Vendedor : public Funcionario {
private:
    double salarioBase;
    double comissao;

public:
    Vendedor(double sb, double c) : salarioBase(sb), comissao(c) {}

    double calcularSalario() override {
        return salarioBase + comissao;
    }
};

class Freelancer : public Funcionario {
private:
    double valorHora;
    double horasTrabalhadas;

public:
    Freelancer(double vh, double ht) : valorHora(vh), horasTrabalhadas(ht) {}

    double calcularSalario() override {
        return valorHora * horasTrabalhadas;
    }
};

int main() {
    vector<Funcionario*> funcionarios;
    int totalFuncionarios;

    cin >> totalFuncionarios;

    for (int i = 0; i < totalFuncionarios; i++) {
        int tipo;
        cin >> tipo;

        if (tipo == 1) {
            double salarioBase, comissao;
            cin >> salarioBase >> comissao;
            funcionarios.push_back(new Vendedor(salarioBase, comissao));
        } else if (tipo == 2) {
            double valorHora, horasTrabalhadas;
            cin >> valorHora >> horasTrabalhadas;
            funcionarios.push_back(new Freelancer(valorHora, horasTrabalhadas));
        }
    }

    cout << "Dados dos Funcionarios:" << endl;
    double salarioTotal = 0.0;

    for (Funcionario* func : funcionarios) {
        func->imprimirSalario();
        salarioTotal += func->calcularSalario();
    }

    cout << "Salario total de todos os funcionarios: " << fixed << setprecision(2) << salarioTotal << endl;

    for (Funcionario* func : funcionarios) {
        delete func;
    }

    return 0;
}
