#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 10;

int N, M;

vector<vector<int>> dist;

vector<tuple<int, int, char>> mov = {
    {-1, 0, 'U'},
    {1, 0, 'D'},
    {0, 1, 'R'},
    {0, -1, 'L'}
};

vector<vector<bool>> blocked;
vector<vector<pair<int, int>>> parent;
vector<vector<char>> parent_move;

bool val(pair<int, int> v) {
    return v.first >= 0 && v.first < N &&
           v.second >= 0 && v.second < M &&
           !blocked[v.first][v.second];
}

int bfs(pair<int, int> a, pair<int, int> b) {
    queue<pair<int, int>> q;

    q.push(a);
    dist[a.first][a.second] = 0;

    while (!q.empty()) {

        auto [i, j] = q.front();
        q.pop();

        if (i == b.first && j == b.second) {
            return dist[i][j];
        }

        for (auto [di, dj, letter] : mov) {

            int new_i = i + di;
            int new_j = j + dj;

            if (val({new_i, new_j}) &&
                dist[new_i][new_j] == INF) {

                dist[new_i][new_j] = dist[i][j] + 1;

                q.push({new_i, new_j});
                parent[new_i][new_j] = {i, j};
                parent_move[new_i][new_j] = letter;
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    dist.assign(N, vector<int>(M, INF));
    blocked.assign(N, vector<bool>(M, false));
    parent.assign(N, vector<pair<int, int>>(M, {-1, -1}));
    parent_move.assign(N, vector<char>(M));
    pair<int, int> A, B;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char x;
            cin >> x;

            if (x == '#')
                blocked[i][j] = true;

            else if (x == 'A')
                A = {i, j};

            else if (x == 'B')
                B = {i, j};
        }
    }

    int ans = bfs(A, B);

    if (ans == -1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n" << ans << '\n';

    vector<char> caminho;

    pair<int,int> atual = B;

    while (atual != A) {
        auto [i, j] = atual;

        caminho.push_back(parent_move[i][j]);
        atual = parent[i][j];

    }
    reverse(caminho.begin(), caminho.end());

    for (char x : caminho) {
      cout << x;
    }
    cout << endl;

    return 0;
}
