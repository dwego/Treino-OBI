#include <iostream>
using namespace std;

int main() {
    int n, m;
    int qtd_camera;
    cin >> n;
    cin >> m;
    cin >> qtd_camera;

    int x;
    int y;
    char orientation;

    bool find = false;

    vector<vector<bool>> blocked(n, vector<bool>(m));

    for (int i = 0; i < qtd_camera; i++) {
        cin >> x;
        cin >> y;
        cin >> orientation;

        if (orientation == 'N') {
            for (int i = x; i >= 0; i--)
                blocked[i][y] = true;
        }
        else if (orientation == 'S') {
            for (int i = x; i < n; i++)
                blocked[i][y] = true;
        }
        else if (orientation == 'L') {
            for (int j = y; j < m; j++)
                blocked[x][j] = true;
        }
        else if (orientation == 'O') {
            for (int j = y; j >= 0; j--)
                blocked[x][j] = true;
        }
    }

    queue<pair<int, int>> q;
    if (!blocked[0][0]) {
        q.push({0, 0});
        blocked[0][0] = true;
    }

    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) {
            find = true;
            break;
        }

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (blocked[nx][ny] == true) {
                continue;
            }

            blocked[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    if (find) {
        cout << "S\n";
    } else {
        cout << "N\n";
    }

}
