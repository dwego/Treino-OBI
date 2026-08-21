#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, X;

    cin >> N >> X;

    // int qtd =
    //    upper_bound(v.begin(), v.end(), b)
    //    - lower_bound(v.begin(), v.end(), a); forma de achar quantas ocorrencias de um mesmo numero

    vector<long long> notas(N);

    for (int i = 0; i < N; i++) {
        cin >> notas[i];
    }

    sort(notas.begin(), notas.end());

    auto it = lower_bound(notas.begin(), notas.end(), X);

    if (it == notas.end()) {
        cout << -1 << '\n';
    } else {
        int posicao = it - notas.begin() + 1;
        cout << posicao << '\n';
    }

    return 0;
}
