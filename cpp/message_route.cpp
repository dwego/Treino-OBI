#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

vector<vector<int>> graph;
vector<int> dist;
vector<int> parent;

int bfs(int ori, int des) {
    queue<int> q;

    q.push(ori);
    dist[ori] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == des)
            return dist[v];

        for (int w : graph[v]) {
            if (dist[w] == INF) {
                dist[w] = dist[v] + 1;
                parent[w] = v;
                q.push(w);
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

    graph.resize(N + 1);
    parent.resize(N + 1, -1);
    dist.resize(N + 1, INF);

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;

        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    int ans = bfs(1, N);

    if (ans == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> caminho;

    for (int v = N; v != -1; v = parent[v]) {
        caminho.push_back(v);
    }

    reverse(caminho.begin(), caminho.end());

    cout << caminho.size() << '\n';

    for (int v : caminho) {
        cout << v << ' ';
    }

    cout << '\n';

    return 0;
}
