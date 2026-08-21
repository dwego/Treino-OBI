#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Exemplo de priority_queue pra rapidez:

    priority_queue<long long> max_heap;
    priority_queue<
        long long,
        vector<long long>,
        greater<long long>
    > min_heap;

    // .push(), .emplace() (referencia especifica, nao utilizarei), .top(), .pop(), .empty(), .size(), .swap(another_queue) (troca os conteudos com outra)

    set<long long> teste_set;      // set -> ordenado, nao repete e O(log N)
    multiset<long long> teste_multiset; // multiset > ordenado, repete e O(log N), se apagar um numero N, ele apaga todas as ocorrencias
    // .insert(), .find(), .erase(), .lower_bound(), .upper_bound()

    map<long long, int> teste_map; // map -> chave, valor
    // teste_map[chave] -> valor
    // for (auto [numero, quantidade] : frequencia) forma de percorrer

    return 0;
}