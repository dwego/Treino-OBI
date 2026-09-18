#include <bits/stdc++.h>
using namespace std;

vector<int> moedas;
vector<vector<signed char>> dp;

int V, M;

bool solve(int i, int soma) {
    if (soma == V)
        return true;

    if (soma > V)
        return false;

    if (i == M)
        return false;

    if (dp[i][soma] != -1)
        return dp[i][soma];

    dp[i][soma] = solve(i + 1, soma);

    if (!dp[i][soma])
        dp[i][soma] = solve(i + 1, soma + moedas[i]);

    return dp[i][soma];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> M;

    moedas.resize(M);

    for (int i = 0; i < M; i++) {
        cin >> moedas[i];
    }

    dp.resize(M, vector<signed char>(V + 1, -1));

    bool ans = solve(0, 0);

    cout << (ans ? "S\n" : "N\n");

    return 0;
}
