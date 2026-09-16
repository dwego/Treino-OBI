#include <bits/stdc++.h>
using namespace std;

vector<int> d;

int tempo_total(int k, int n){
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < k; i++) {
    pq.push(d[i]);
  }

  for (int i = k; i < n; i++) {
    int termina = pq.top();
    pq.pop();

    pq.push(termina + d[i]);
  }

    int tempoFinal = 0;
    while (!pq.empty()) {
        tempoFinal = max(tempoFinal, pq.top());
        pq.pop();
    }

    return tempoFinal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;

    int x;
    for (int i = 0; i < N; i++) {
      cin >> x;
        d.push_back(x);
    }

    int l = 1, r = T;

    while(l < r) {
      int K = (l + r) / 2;
      if (tempo_total(K, N) > T) l = K + 1;
      else r = K;
    }

    cout << l << endl;

    return 0;
}
