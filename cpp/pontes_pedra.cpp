#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 200005;

int visited[MAXN];
int ouro[MAXN];
vector<vector<int>> pontes(MAXN);

int n, m, k;

int dfs(int v, int X) {
    visited[v] = true;

    int total = 1;

    for (int w : pontes[v]) {
        if (!visited[w] && ouro[w] >= X) {
            total += dfs(w, X);
        }
    }

    return total;
}

bool possible(int X) {
    fill(visited, visited + n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i] && ouro[i] >= X) {

            int tamanho = dfs(i, X);

            if (tamanho >= k) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> ouro[i];
    }

    int i, j;

    for (int idx = 0; idx < m; idx++) {
        cin >> i >> j;

        pontes[i - 1].push_back(j - 1);
        pontes[j - 1].push_back(i - 1);
    }

    int l = 0, r = 1e9;

    while (l < r) {
        int chute = l + (r - l + 1) / 2;

        if (possible(chute))
            l = chute;
        else
            r = chute - 1;
    }

    cout << l << endl;

    return 0;
}
