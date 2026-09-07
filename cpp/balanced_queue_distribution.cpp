#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    vector<int> numeros(N);

    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }

    vector<vector<int>> fila(F);
    vector<int> peso(F, 0);

    for ( int x : numeros ) {
        int melhor = 0;

        for (int i = 0; i < F; i++) {
            if (peso[i] < peso[melhor]) {
                melhor = i;
            }
        }

        fila[melhor].push_back(x);
        peso[melhor]+=x;
    }

    for (int i = 0; i < F; i++) {
        for (int x : fila[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
