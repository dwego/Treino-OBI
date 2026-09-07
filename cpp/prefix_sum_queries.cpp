#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> valores(N);
    vector<long long> prefixos(N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> valores[i];
    }

    for (int i = 1; i <= N; i++) {
        prefixos[i] = prefixos[i - 1] + valores[i - 1];
    }

    for (int i = 0; i < Q; i++) {
        int inicio, ultimo;
        cin >> inicio >> ultimo;

        long long soma =
            prefixos[ultimo] - prefixos[inicio - 1];

        cout << soma << '\n';
    }

    return 0;
}
