#include <bits/stdc++.h>
using namespace std;

int N, K;
constexpr int MAXN = 200000;
int cidades[MAXN];

// K -> até D de distancia entre cidade[i] - cidade[i-1], cidades, total cidades: N

bool possible(int D) {
  int l = 0;
  int total = 1;

  for (int r = 1; r < N; r++) {
    if (cidades[r] - cidades[l] > D) {
      total += 1;
      l = r;
    }
    if (total > K) {
      return 0;
    }
  }
  return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> cidades[i];

    int l = 0, r = 1e9+10;
    while (l < r) {
      int d = (l + r)/2;
      if (!possible(d)) l = d+1;
      else r = d;
    }

    cout << l << endl;
    return 0;
}
