#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

// Pedro Mattar

using namespace std;

class Funcionario {
protected:
    string nome;
    float salario;
public:
    void setNome(string n) { nome = n; }
    string getNome() { return nome; }
    void setSalario(float s) { salario = s; }
    float getSalario() { return salario; }

    virtual void imprime() {
        cout << "Dados do Funcionario:\nNome: " << nome
             << fixed << setprecision(2) << "\nSalario: " << salario << endl;
    }
};

class Gerente : public Funcionario {
    float bonus;
public:
    void setBonus(float b) { bonus = b; }
    float getBonus() { return bonus; }

    void imprime() override {
        Funcionario::imprime();
        cout << fixed << setprecision(2) << "Bonus Gerente: " << bonus << endl;
    }
};

int main() {
    Funcionario f;
    Gerente g;


    string nome;
    getline(cin, nome);
    f.setNome(nome);

    float salario;
    cin >> salario;
    f.setSalario(salario);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, nome);
    g.setNome(nome);

    cin >> salario;
    g.setSalario(salario);

    float bonus;
    cin >> bonus;
    g.setBonus(bonus);


    f.imprime();
    g.imprime();

    return 0;
}
