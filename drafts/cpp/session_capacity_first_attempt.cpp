#include <iostream>
using namespace std;

int main() {
    int N, S, C;
    cin >> N >> S >> C;

    vector<int> pessoa_tempo(N);
    vector<int> fechamento_sessao(S);

    for ( int &x : pessoa_tempo ){
        cin >> x;
    }

    for ( int &x : fechamento_sessao ){
        cin >> x;
    }

    vector<int> pessoasPorSessao(S, 0);

    int indice_pessoa = 0;

    for (int i_sessao = 0; i_sessao < S; i_sessao++) {
        while(
            indice_pessoa < N &&
            pessoasPorSessao[i_sessao] < C &&
            pessoa_tempo[indice_pessoa] <= fechamento_sessao[i_sessao]
        ) {
            pessoasPorSessao[i_sessao]++;
            indice_pessoa++
        }
    }

}
