#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

// Pedro Mattar

using namespace std;

class Livro {
private:
    string titulo;
    int numeroPaginas;

public:
    Livro(string titulo, int numeroPaginas) {
        this->titulo = titulo;
        this->numeroPaginas = numeroPaginas;
    }

    string getTitulo() {
        return titulo;
    }

    void setTitulo(string novoTitulo) {
        titulo = novoTitulo;
    }

    int getNumeroPaginas() {
        return numeroPaginas;
    }

    void setNumeroPaginas(int novoNumeroPaginas) {
        numeroPaginas = novoNumeroPaginas;
    }
};

int main() {
    string tituloInicial;
    int paginasInicial;

    getline(cin, tituloInicial);
    tituloInicial.erase(remove(tituloInicial.begin(), tituloInicial.end(), '\r'), tituloInicial.end());

    cin >> paginasInicial;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Livro livro(tituloInicial, paginasInicial);

    cout << "Detalhes iniciais do livro:" << endl;
    cout << "Titulo: " << livro.getTitulo() << endl;
    cout << "Numero de Paginas: " << livro.getNumeroPaginas() << endl;

    string subtitulo;
    getline(cin, subtitulo);
    subtitulo.erase(remove(subtitulo.begin(), subtitulo.end(), '\r'), subtitulo.end());

    livro.setTitulo(livro.getTitulo() + ": " + subtitulo);
    livro.setNumeroPaginas(livro.getNumeroPaginas() + 50);

    cout << "Detalhes modificados do livro:" << endl;
    cout << "Titulo: " << livro.getTitulo() << endl;
    cout << "Numero de Paginas: " << livro.getNumeroPaginas() << endl;

    return 0;
}
