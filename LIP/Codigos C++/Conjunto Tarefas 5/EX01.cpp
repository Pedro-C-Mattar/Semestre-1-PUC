#include <iostream>
#include <cmath>
#include <iomanip>

// Pedro Mattar

using namespace std;

class Forma {
public:

    virtual double calcularArea() const = 0;

    void imprimirArea() const {
        cout << fixed << setprecision(2);
        cout << "Area: " << calcularArea() << endl;
    }

    virtual ~Forma() {}
};

class Circulo : public Forma {
private:
    double raio;

public:

    Circulo(double r) : raio(r) {}

    double calcularArea() const override {
        return M_PI * raio * raio;
    }

    void imprimirDados() const {
        cout << "Dados do Circulo:" << endl;
        imprimirArea();
    }
};

class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:

    Retangulo(double l, double a) : largura(l), altura(a) {}

    double calcularArea() const override {
        return largura * altura;
    }

    void imprimirDados() const {
        cout << "Dados do Retangulo:" << endl;
        imprimirArea();
    }
};

int main() {
    double raio, largura, altura;

    cin >> raio;
    cin >> largura >> altura;

    Circulo circulo(raio);
    Retangulo retangulo(largura, altura);

    circulo.imprimirDados();
    retangulo.imprimirDados();

    return 0;
}
