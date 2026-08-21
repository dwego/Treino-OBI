#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// SLIDING WINDOW USING FREQUENCY

int main() {
    int n;
    cin >> n;

    int l = 0;
    int ans = 0;

    vector<int> v(n);
    vector<int> freq(100001, 0);

    for (int &x : v)
        cin >> x;

    for (int r = 0; r < n; r++) {
        freq[v[r]]++;

        while (freq[v[r]] > 1) {
            freq[v[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
}
