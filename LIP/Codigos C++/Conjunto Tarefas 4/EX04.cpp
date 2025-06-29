#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

// Pedro Mattar

using namespace std;

class Produto {
protected:
    string nome;
    float preco;

public:
    Produto() : nome(""), preco(0.0f) {}
    Produto(string nome, float preco) : nome(nome), preco(preco) {}

    string getNome() const { return nome; }
    void setNome(string novoNome) { nome = novoNome; }

    float getPreco() const { return preco; }
    void setPreco(float novoPreco) { preco = novoPreco; }

    virtual void imprime() const {
        cout << "Dados do Produto:" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Preco: " << fixed << setprecision(2) << preco << endl;
    }
};

class ProdutoEletronico : public Produto {
private:
    int garantia;

public:
    ProdutoEletronico() : Produto(), garantia(0) {}
    ProdutoEletronico(string nome, float preco, int garantia)
        : Produto(nome, preco), garantia(garantia) {}

    int getGarantia() const { return garantia; }
    void setGarantia(int novaGarantia) { garantia = novaGarantia; }

    void estenderGarantia(int meses) {
        garantia += meses;
    }

    void imprime() const override {
        Produto::imprime();
        cout << "Garantia: " << garantia << " meses" << endl;
    }
};

void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    string nomeProduto, nomeEletronico;
    float precoProduto, precoEletronico;
    int garantia, mesesExtensao;

    getline(cin, nomeProduto);
    cin >> precoProduto;
    limparBuffer();

    getline(cin, nomeEletronico);
    cin >> precoEletronico >> garantia;
    limparBuffer();

    Produto produto(nomeProduto, precoProduto);
    ProdutoEletronico produtoEletronico(nomeEletronico, precoEletronico, garantia);

    produto.imprime();
    produtoEletronico.imprime();

    cin >> mesesExtensao;
    produtoEletronico.estenderGarantia(mesesExtensao);

    produtoEletronico.imprime();

    return 0;
}
