#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, f; cin >> n >> f;

    int numero_atual;
    vector<vector<int>> filas(f);

    set<pair<int, int>> pesos; // peso, indice

    for (int i  = 0; i < f; i++) {
      pesos.insert({0, i});
    }

    for (int i = 0; i < n; i++) {
      cin >> numero_atual;

      auto it = pesos.begin();

      int peso = it->fi;
      int indice = it->se;

      pesos.erase(it);

      filas[indice].push_back(numero_atual);
      peso += numero_atual;

      pesos.insert({peso, indice});
    }

    for (int i = 0; i < f; i++) {
      for (auto x : filas[i]) {
        cout << x << " ";
      }
      cout << "\n";
    }

    return 0;
}
