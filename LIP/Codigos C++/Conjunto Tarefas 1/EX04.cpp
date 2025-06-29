
#include <iostream>
#include <stdio.h>

using namespace std;

class Retangulo {
public:
    float largura;
    float altura;

public:
    void lerAtributos(){
        cin >> largura;
        cin >> altura;
    }

    float calcArea(){
        return largura * altura;
    }

    void imprimir(){
        printf("Largura: %.2f, Altura: %.2f\n", largura, altura);
        printf("Area do retangulo: %.2f", calcArea());
    }
};

int main() {
    Retangulo retangulo;

    retangulo.lerAtributos();

    retangulo.imprimir();

    return 0;
}


