#include <bits/stdc++.h>
using namespace std;

int inf = 1e9 + 10;

vector<vector<pair<int, int>>> adj; // pair<indice, peso>

int djikstra(int o, int d, vector<pair<bool, int>> dist) {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[o] = {false, 0};
    pq.push({0, o});

    while (!pq.empty()) {
        int dist_atual = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v].first == true) {
            continue;
        }

        dist[v].first = true;

        if (v == d) {
            return dist_atual;
        }

        for (auto w : adj[v]) {
            int vizinho = w.first;
            int peso = w.second;

            int nova_dist = dist_atual + peso;

            if (dist[vizinho].second == inf ||
                nova_dist < dist[vizinho].second) {

                dist[vizinho].second = nova_dist;

                pq.push({
                    nova_dist,
                    vizinho
                });
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // vertices: 0 até N
    adj.resize(N + 2);


    vector<pair<bool, int>> dist(
        N + 2,
        {false, inf}
    );

    for (int i = 0; i < M; i++) {
        int S, T, B;
        cin >> S >> T >> B;

        adj[S].push_back({T, B});
        adj[T].push_back({S, B});
    }

    cout << djikstra(0, N + 1, dist) << '\n';

    return 0;
}
