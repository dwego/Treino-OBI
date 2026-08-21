#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    bool find = false;

    vector<vector<int>> grid(n, vector<int>(m)); // n: row, m: column
    vector<vector<bool>> vis(n, vector<bool>(m, false)); // same matrix but visible

    queue<pair<int, int>> q;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    q.push({0, 0});
    vis[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) {
                find = true;
                break;
            }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            // 1. vê se continua dentro da grade
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // 2. vê se já visitou
            if (vis[nx][ny])
                continue;

            // 3. marca e coloca na fila
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
        // processa (x, y)
    }

    if (find)
        cout << "S\n";
    else
        cout << "N\n";
}
