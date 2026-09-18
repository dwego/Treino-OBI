#include <bits/stdc++.h>
using namespace std;

int N = 8, M = 8;
const int INF = 1e9 + 10;

vector<vector<int>> dist;

vector<pair<int, int>> mov = {
    {2, -1}, {2, 1},
    {-2, -1}, {-2, 1},
    {1, -2}, {1, 2},
    {-1, -2}, {-1, 2}
};

bool valid(pair<int, int> v) {
    return v.first >= 0 && v.first < N &&
           v.second >= 0 && v.second < M;
}

int bfs(pair<int, int> knight_pos, pair<int, int> des) {
    queue<pair<int, int>> q;

    dist[knight_pos.first][knight_pos.second] = 0;
    q.push(knight_pos);

    while (!q.empty()) {

        auto [i, j] = q.front();
        q.pop();

        if (i == des.first && j == des.second) {
            return dist[i][j];
        }

        for (auto w : mov) {

            w.first += i;
            w.second += j;

            if (valid(w) && dist[w.first][w.second] == INF) {

                dist[w.first][w.second] = dist[i][j] + 1;

                q.push(w);
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dist.resize(N, vector<int>(M, INF));

    pair<int, int> inicio = {0, 0};
    pair<int, int> destino = {7, 7};

    cout << bfs(inicio, destino) << '\n';

    return 0;
}
