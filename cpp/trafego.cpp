#include <bits/stdc++.h>
using namespace std;

struct Rua {
  int B;
  int D;
  int G;
  int R;
};

int INF = 1e9+10;
vector<vector<Rua>> grafo;
vector<int> dist;

int dijkstra(int origem, int destino) {
  priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

  dist[origem] = 0;
  pq.push({0, origem});

  while(!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (d > dist[v]) {
      continue;
    }

    for (auto w : grafo[v]) {
        int chegada = d + w.D;
        int ciclo = w.G + w.R;
        int momento = chegada % ciclo;

        int aumento = 0;

        if (momento >= w.G) {
            aumento = ciclo - momento;
        }

        int nova_dist = chegada + aumento;

        if (nova_dist < dist[w.B]) {
            dist[w.B] = nova_dist;
            pq.push({nova_dist, w.B});
        }
    }
  }
  return dist[destino] == INF ? -1 : dist[destino];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, A, B, D, G, R; cin >> N >> M;

    grafo.resize(N);
    dist.resize(N, INF);
    for (int i = 0; i < M; i++) {
      cin >> A >> B >> D >> G >> R;
      A--;
      B--;
      grafo[A].push_back({B, D, G, R});
    }

    cout << dijkstra(0, N-1) << endl;

    return 0;
}
