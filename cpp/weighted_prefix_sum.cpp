#include <iostream>
#include <vector>
using namespace std;

// PREFIX_SUM (IMPORTANTE)

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    vector<long long> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pref[i + 1] = pref[i] + v[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        long long soma = pref[r] - pref[l - 1];
        long long k = r - l + 1;

        cout << 11LL * (k - 1) * soma << '\n';
    }
}
