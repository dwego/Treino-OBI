#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo = {
    {1, 2},
    {0, 3, 4},
    {0, 5},
    {1},
    {1, 5},
    {2, 4}
};

vector<vector<pair<int, int>>> grafo_dijkstra = {
    {{1, 4}, {2, 2}},
    {{0, 4}, {3, 3}},
    {{0, 2}, {3, 1}},
    {{1, 3}, {2, 1}}
};

vector<bool> visited(10, false);
vector<int> dist(10, -1);
vector<pair<bool, int>> vis_dist(10, {false, -1});

int bfs(int inicio, int destino) {
    fill(dist.begin(), dist.end(), -1);

    queue<int> q;

    dist[inicio] = 0;
    q.push(inicio);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == destino) {
            return dist[v];
        }

        for (int w : grafo[v]) {
            if (dist[w] == -1) {
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }
    }

    return -1;
}

int dijkstra(int o, int d) {
    fill(vis_dist.begin(), vis_dist.end(), make_pair(false, -1));

    // {distancia, vertice}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vis_dist[o] = {false, 0};
    pq.push({0, o});

    while (!pq.empty()) {
        int dist_atual = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (vis_dist[v].first) {
            continue;
        }

        vis_dist[v].first = true;

        if (v == d) {
            return dist_atual;
        }

        for (auto w : grafo_dijkstra[v]) {
            int vizinho = w.first;
            int peso = w.second;

            int nova_dist = dist_atual + peso;

            if (
                vis_dist[vizinho].second == -1 ||
                nova_dist < vis_dist[vizinho].second
            ) {
                vis_dist[vizinho].second = nova_dist;
                pq.push({nova_dist, vizinho});
            }
        }
    }

    return -1;
}

bool dfs(int inicio, int destino) {
    if (inicio == destino) {
        return true;
    }

    visited[inicio] = true;

    for (int w : grafo[inicio]) {
        if (!visited[w]) {
            if (dfs(w, destino)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "BFS 0 -> 5: " << bfs(0, 5) << '\n';

    fill(visited.begin(), visited.end(), false);
    cout << "DFS 0 -> 5: " << dfs(0, 5) << '\n';

    cout << "Dijkstra 0 -> 3: " << dijkstra(0, 3) << '\n';

    return 0;
}
