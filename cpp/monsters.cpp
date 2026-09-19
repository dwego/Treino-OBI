  #include <bits/stdc++.h>
  using namespace std;

  #define f first
  #define s second
  int N, M;

  const int INF = 1e9+10;

  vector<vector<int>> dist_ms;
  vector<vector<int>> dist_s;
  vector<tuple<int, int, char>> mov = {
    {-1, 0, 'U'}, {1, 0, 'D'},
    {0, -1, 'L'}, {0, 1, 'R'}
  };

  vector<vector<pair<int, int>>> parent;
  vector<vector<char>> parent_letter;
  vector<vector<bool>> blocked;

  vector<pair<int, int>> ms;

  bool val(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M &&
          !blocked[i][j];
  }

  pair<int, int> bfs(pair<int, int> a) {
    queue<pair<int, int>> q;
    q.push({a.f, a.s});
    dist_s[a.f][a.s] = 0;

    while(!q.empty()) {
      auto [i, j] = q.front(); q.pop();

      if (i + 1 == N || i == 0 || j + 1 == M || j == 0) {
        return {i, j};
      }

      for (auto [di, dj, letter] : mov) {
        di += i;
        dj += j;

        if (val(di, dj) && dist_s[di][dj] == INF && dist_s[i][j] + 1 < dist_ms[di][dj]) {
          q.push({di, dj});
          dist_s[di][dj] = dist_s[i][j] + 1;

          parent[di][dj] = {i, j};
          parent_letter[di][dj] = letter;
        }
      }
    }
    return {-1, -1};
  }

  void bfs_ms (vector<pair<int, int>> ms) {
    queue<pair<int, int>> q;
    for (auto s : ms) {
      q.push({s.f, s.s});
      dist_ms[s.f][s.s] = 0;
    }

    while(!q.empty()) {
      auto [i, j] = q.front(); q.pop();

      for (auto [di, dj, l] : mov) {
        di += i;
        dj += j;

        if (val(di, dj) && dist_ms[di][dj] == INF) {
          q.push({di, dj});
          dist_ms[di][dj] = dist_ms[i][j] + 1;
        }
      }
    }
  }

  int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
      cin >> N >> M;
      pair<int, int> A;

      dist_ms.assign(N, vector<int>(M, INF));
      dist_s.assign(N, vector<int>(M, INF));
      blocked.assign(N, vector<bool>(M, false));
      parent.assign(N, vector<pair<int, int>>(M, {-1, -1}));
      parent_letter.assign(N, vector<char>(M));

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          char x;
          cin >> x;

          if (x == '#') blocked[i][j] = true;
          else if (x == 'A') A = {i, j};
          else if (x == 'M') ms.push_back({i, j});
        }
      }

      bfs_ms(ms);

      pair<int, int> ans = bfs(A);

      if (ans.f == -1 && ans.s == -1) {
        cout << "NO" << endl;
        return 0;
      }

      cout << "YES" << endl << dist_s[ans.f][ans.s] << endl;

      vector<char> caminho;
      auto atual = ans;

      while (atual != A) {
        auto [i, j] = atual;

          caminho.push_back(parent_letter[i][j]);
          atual = parent[i][j];
      }

      reverse(caminho.begin(), caminho.end());

      for (char x : caminho) {
        cout << x;
      }
      cout << endl;

      return 0;
  }
