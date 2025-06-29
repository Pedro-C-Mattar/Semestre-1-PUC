

#include <iostream>
#include <stdio.h>

using namespace std;

class Circulo {
public:
    float raio;

public:
    void lerAtributos(){
        cin >> raio;
    }

    float calcCirculo(float pi){
        return 2*pi*raio;
    }

    void imprimir(float pi){
        printf("Raio:%.2f\n", raio);
        printf("Circunferencia do circulo: %.2f", calcCirculo(pi));
    }
};

int main() {
    Circulo circulo;

    float pi = 3.1415;

    circulo.lerAtributos();

    circulo.imprimir(pi);

    return 0;
}


