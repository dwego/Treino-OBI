#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<vector<pair<int, int>>> grafo; // vertice, peso
vector<long long> dist;

void dijkstra(int S) {
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;

        for (auto [vizinho, peso] : grafo[v]) {
            if (dist[v] + peso < dist[vizinho]) {
                dist[vizinho] = dist[v] + peso;
                pq.push({dist[vizinho], vizinho});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    grafo.resize(N + 1);
    dist.resize(N + 1, INF);

    for (int i = 0; i < M; i++) {
        int U, V, P;
        cin >> U >> V >> P;

        grafo[U].push_back({V, P});
        grafo[V].push_back({U, P});
    }

    int S;
    cin >> S;

    dijkstra(S);

    long long menor = INF;
    long long maior = 0;

    for (int i = 1; i <= N; i++) {
        if (i == S) continue;

        menor = min(menor, dist[i]);
        maior = max(maior, dist[i]);
    }

    cout << maior - menor << '\n';

    return 0;
}
