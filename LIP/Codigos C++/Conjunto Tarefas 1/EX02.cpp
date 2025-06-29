#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Livro {
public:
    string titulo;
    string autor;

public:
    void imprimir(){
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
    }

};

int main() {
    Livro livro;

    string titulo;
    string autor;

    getline(cin, titulo);
    getline(cin, autor);

    livro.titulo = titulo;
    livro.autor = autor;

    livro.imprimir();

    return 0;
}

