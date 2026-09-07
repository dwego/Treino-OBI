#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<string> joias;

    for (int i = 0; i < n; i++) {
      string temp;
      cin >> temp;
      joias.insert(temp);
    }

    // .erase funciona tb ;)

    cout << joias.size() << endl;

    return 0;
}
