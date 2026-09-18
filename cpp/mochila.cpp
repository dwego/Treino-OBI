#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> items; // peso, valor
vector<vector<int>> dp;

int N;

int solve(int idx, int capacidade) {
    if (idx == N) {
        return 0;
    }

    if (dp[idx][capacidade] != -1) {
        return dp[idx][capacidade];
    }

    auto [peso, valor] = items[idx];

    int nao_pega = solve(idx + 1, capacidade);

    int pega = 0;

    if (peso <= capacidade) {
        pega = valor + solve(idx + 1, capacidade - peso);
    }

    return dp[idx][capacidade] = max(pega, nao_pega);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> N >> C;

    items.resize(N);
    dp.resize(N, vector<int>(C + 1, -1));

    for (auto &[peso, valor] : items) {
        cin >> peso >> valor;
    }

    cout << solve(0, C) << '\n';

    return 0;
}
