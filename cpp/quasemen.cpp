#include <bits/stdc++.h>
using namespace std;

int inf = 1e9+10;
vector<vector<tuple<int, int, int>>> grafo;
vector<int> dist;
vector<vector<pair<int, int>>> parent; // vertice, id_rota
vector<bool> blocked;

void dfs(int v) {
    dist[v] = inf;
    for (auto [w, id] : parent[v]) {
        blocked[id] = true;
        if (dist[w] != inf) {
            dfs(w);
        }
    }
}

int dijkstra(int o, int des) {
  priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

  dist[o] = 0;
  pq.push({0, o});

  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    if (d > dist[v]) {
      continue;
    }

    for (auto [vizinho, peso, id] : grafo[v] ) {
      int nova_dist = d + peso;

      if (blocked[id]) continue;

      if (nova_dist < dist[vizinho]) {
          dist[vizinho] = nova_dist;
          parent[vizinho].clear();
          parent[vizinho].push_back({v, id});
          pq.push({nova_dist, vizinho});
      }
      else if (nova_dist == dist[vizinho]) {
        parent[vizinho].push_back({v, id});
      }
    }
  }
  return dist[des] == inf ? -1 : dist[des];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
      int N, M, S, D; cin >> N >> M;
      if (N == 0 && M == 0) {
        break;
      }
      cin >> S >> D;

      grafo.assign(N, {});
      dist.assign(N, inf);
      blocked.assign(M + 1, false);
      parent.assign(N, {});
      int U, V, P;

      int id = 1;
      for (int i = 0; i < M; i++) {
        cin >> U >> V >> P;
        grafo[U].push_back({V, P, id});
        id++;
      }

      dijkstra(S, D);
      dfs(D);
      fill(dist.begin(), dist.end(), inf);
      cout << dijkstra(S, D) << endl;
    }
    return 0;
}
