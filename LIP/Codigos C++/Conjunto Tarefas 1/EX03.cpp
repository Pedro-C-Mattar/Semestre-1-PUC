
#include <iostream>
#include <stdio.h>

using namespace std;

class Retangulo {
public:
    int largura;
    int altura;

public:
    int calcArea(){
        return largura * altura;
    }

};

int main() {
    Retangulo retangulo;

    int largura;
    int altura;
    int area;

    cin >> largura;
    cin >> altura;

    retangulo.largura = largura;
    retangulo.altura = altura;

    area = retangulo.calcArea();
    cout << area << endl;

    return 0;
}

