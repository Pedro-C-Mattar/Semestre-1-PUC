#include <iostream>
#include <string>
#include <limits>

// Pedro Mattar

using namespace std;

class Veiculo {
private:
    string marca;
    int anoFabricacao;

public:
    string getMarca() {
        return marca;
    }

    int getAnoFabricacao() {
        return anoFabricacao;
    }

    void setMarca(string novaMarca) {
        marca = novaMarca;
    }

    void setAnoFabricacao(int novoAno) {
        anoFabricacao = novoAno;
    }
};

class Carro : public Veiculo {
private:
    int numeroPortas;

public:
    int getNumeroPortas() {
        return numeroPortas;
    }

    void setNumeroPortas(int portas) {
        numeroPortas = portas;
    }
};

int main() {
    Veiculo veiculo;
    string marcaVeiculo;
    int anoVeiculo;

    getline(cin, marcaVeiculo);
    cin >> anoVeiculo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    veiculo.setMarca(marcaVeiculo);
    veiculo.setAnoFabricacao(anoVeiculo);

    cout << "Dados do Veiculo:" << endl;
    cout << "Marca: " << veiculo.getMarca() << endl;
    cout << "Ano de Fabricacao: " << veiculo.getAnoFabricacao() << endl;

    Carro carro;
    string marcaCarro;
    int anoCarro, portasCarro;

    getline(cin, marcaCarro);
    cin >> anoCarro;
    cin >> portasCarro;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    carro.setMarca(marcaCarro);
    carro.setAnoFabricacao(anoCarro);
    carro.setNumeroPortas(portasCarro);

    cout << "Dados do Carro:" << endl;
    cout << "Marca: " << carro.getMarca() << endl;
    cout << "Ano de Fabricacao: " << carro.getAnoFabricacao() << endl;
    cout << "Numero de Portas: " << carro.getNumeroPortas() << endl;

    return 0;
}
