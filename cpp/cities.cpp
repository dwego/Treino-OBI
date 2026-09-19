#include <bits/stdc++.h>
using namespace std;

int N, M;

const long long INF = 4e18;

vector<vector<pair<int, int>>> graph;
vector<long long> dist;

void dijkstra() {
  priority_queue<
    pair<long long, int>,
    vector<pair<long long, int>>,
    greater<pair<long long, int>>> pq;

  dist[0] = 0;
  pq.push({0, 0});

  while(!pq.empty()) {
    auto [d, v] = pq.top(); pq.pop();

    if (d > dist[v]) {
      continue;
    }

    for (auto [w, weight] : graph[v]) {
        long long nova_dist = d + weight;

        if (nova_dist < dist[w]) {
            dist[w] = nova_dist;
            pq.push({nova_dist, w});
        }
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N);
    dist.resize(N, INF);

    for (int i = 0; i < M; i++) {
      int U, V, P;
      cin >> U >> V >> P;

      U--;
      V--;
      graph[U].push_back({V, P});
    }

    dijkstra();

    for (int i = 0; i < N; i++) {
      cout << dist[i] << " ";
    }

    cout << endl;

    return 0;
}
