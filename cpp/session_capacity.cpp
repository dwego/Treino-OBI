#include <iostream>
#include <vector>
using namespace std;

int main() {
    int quantidadePessoas, quantidadeSessoes, capacidadeSessao;
    cin >> quantidadePessoas >> quantidadeSessoes >> capacidadeSessao;

    vector<int> horarioCompra(quantidadePessoas);
    vector<int> horarioFechamento(quantidadeSessoes);

    for (int i = 0; i < quantidadePessoas; i++) {
        cin >> horarioCompra[i];
    }

    for (int i = 0; i < quantidadeSessoes; i++) {
        cin >> horarioFechamento[i];
    }

    vector<int> pessoasPorSessao(quantidadeSessoes, 0);

    int indicePessoa = 0;

    for (int indiceSessao = 0; indiceSessao < quantidadeSessoes; indiceSessao++) {

        while (
            indicePessoa < quantidadePessoas &&
            pessoasPorSessao[indiceSessao] < capacidadeSessao &&
            horarioCompra[indicePessoa] <= horarioFechamento[indiceSessao]
        ) {
            pessoasPorSessao[indiceSessao]++;
            indicePessoa++;
        }
    }

    for (int indiceSessao = 0; indiceSessao < quantidadeSessoes; indiceSessao++) {
        cout << pessoasPorSessao[indiceSessao] << '\n';
    }
}
