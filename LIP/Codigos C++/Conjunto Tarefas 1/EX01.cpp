#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Livro {
public:
    string titulo;
    string autor;
};

int main() {
    Livro livro;

    string titulo;
    string autor;

    getline(cin, titulo);
    getline(cin, autor);

    livro.titulo = titulo;
    livro.autor = autor;

    cout << "Titulo: " << livro.titulo << endl;
    cout << "Autor: " << livro.autor << endl;

    return 0;
}
