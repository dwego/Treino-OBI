#include <bits/stdc++.h>
using namespace std;

int N;
int inf = 1e9+10;
vector<vector<int>> dist; // distancia

int djikstra(vector<vector<bool>> mine) {
  priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
        > pq;

  int di[] = {-1, 1, 0, 0};
  int dj[] = {0, 0, -1, 1};

  dist[0][0] = 0;
  pq.push({0, {0, 0}});

  while (!pq.empty()) {
    auto [d, pos] = pq.top();
    pq.pop();

    auto [i, j] = pos;

    if (d > dist[i][j]) continue;

    for (int k = 0; k < 4; k++) {
      int ni = i + di[k];
      int nj = j + dj[k];

      if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;

      int peso = mine[ni][nj];
      if (dist[i][j] + peso < dist[ni][nj]) {
        dist[ni][nj] = peso + dist[i][j];
        pq.push({
                    dist[ni][nj],
                    {ni, nj}
                });
        }
    }
  }

  return dist[N-1][N-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<vector<bool>> mine(N, vector<bool> (N));
    dist.resize(N, vector<int>(N, inf));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int x;
            cin >> x;
            mine[i][j] = x;
      }
    }

    cout << djikstra(mine) << endl;
    return 0;
}
