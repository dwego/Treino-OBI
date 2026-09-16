#include <bits/stdc++.h>
using namespace std;

int inf = 1e9+10;
int N, M, C, K; // 0 -> A, C -> Destino,
int U, V, P;
vector<vector<pair<int, int>>> grafo;
vector<int> dist;

int dijkstra(int o) {
  priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

  dist[o] = 0;
  pq.push({0, o});

  while(!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (v == C-1) {
      return d;
    }

    if (d > dist[v]) {
      continue;
    }

    for ( auto w : grafo[v] ) {
      auto [vizinho, p] = w;

      if (v < C - 1 && vizinho != v + 1) {
          continue;
      }

      int nova_dist = d + p;
      if (nova_dist < dist[vizinho]) {
        dist[vizinho] = nova_dist;
        pq.push({nova_dist, vizinho});
      }
    }
  }
  return dist[C - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> C >> K;

    grafo.resize(N);
    dist.resize(N, inf);

    for (int i = 0; i < M; i++) {
      cin >> U >> V >> P;
      grafo[U].push_back({V, P});
      grafo[V].push_back({U, P});
    }

    cout << dijkstra(K) << endl;

    return 0;
}
