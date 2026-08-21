#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long X;

    cin >> N >> X;

    vector<long long> valores(N);

    for (int i = 0; i < N; i++) {
        cin >> valores[i];
    }

    sort(valores.begin(), valores.end());

    int l = 0;
    int r = N - 1;

    long long total = 0;

    while (l < r) {
        long long soma = valores[l] + valores[r];

        if (soma <= X) {
            total += r - l;
            l++;
        } else {
            r--;
        }
    }

    cout << total << '\n';

    return 0;
}