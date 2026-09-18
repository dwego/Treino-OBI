#include <bits/stdc++.h>
using namespace std;

int N, K;
int MOD = 1e9+7;
vector<vector<int>> dp;

int solve(int i, int consecutivos) {
    if (i == N)
        return 1;

    if (dp[i][consecutivos] != -1) {
      return dp[i][consecutivos];
    }

    dp[i][consecutivos] = 0;

    // colocar 0
    dp[i][consecutivos] += solve(i + 1, 0);
    dp[i][consecutivos] %= MOD;

    // colocar 1
    if (consecutivos + 1 < K)
        dp[i][consecutivos] += solve(i + 1, consecutivos + 1);
        dp[i][consecutivos] %= MOD;

    return dp[i][consecutivos];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;

    dp.resize(N, vector<int>(K + 1, -1));
    cout << solve(0, 0);
    return 0;
}
