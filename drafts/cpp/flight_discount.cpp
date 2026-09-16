#include <bits/stdc++.h>
using namespace std;

int N, M;
int inf = 1e9+10;

vector<vector<pair<int, int>>> grafo;

int dijkstra(int o, int destino, vector<int> dist) {
  priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

    dist[o] = 0;
    pq.push({0, o});


    while(!pq.empty()) {
      auto [d, v] = pq.top();
      pq.pop();

      if (d > dist[v]) {
        continue;
      }

      if (v == destino) {
        return d;
      }

      for (auto [vizinho, peso] : grafo[v]) {
        int nova_dist = d + peso;

        if (nova_dist < dist[vizinho]) {
          dist[vizinho] = nova_dist;
          pq.push({nova_dist, vizinho});
          maior_peso = max(maior_peso, peso);
        }
      }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    grafo.resize(N);

    vector<int> dist1(N, inf);
    vector<int> distN(N, inf);
    vector<tuple<int,int,int>> arestas;
    for (int i = 0; i < M; i++) {
        int U, V, P;
        cin >> U >> V >> P;

        U--;
        V--;

        grafo[U].push_back({V, P});
        grafo[V].push_back({U, P});
        arestas.push_back({U, V, P});
    }
    int ir = dijkstra(0, N-1, dist1);
    int voltar = dijkstra(N-1, 0, distN);

    cout << dijkstra(0, N-1) << endl;
    return 0;
}
