#include <iostream>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;

    int odd_cost = 0;
    int even_cost = 0;
    vector<vector<int>> cookies(n, vector<int>(m));

    vector<vector<int>> even_cookies(n, vector<int>(m));
    vector<vector<int>> odd_cookies(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cookies[i][j];
            even_cookies[i][j] = cookies[i][j];
            odd_cookies[i][j] = cookies[i][j];

            if ((i + j) % 2 == 0 && cookies[i][j] % 2 == 0) {
                odd_cost++;
                odd_cookies[i][j]++;
            } else if ((i + j) % 2 != 0 && cookies[i][j] % 2 != 0) {
                odd_cost++;
                odd_cookies[i][j]++;
            }

            if ((i + j) % 2 == 0 && cookies[i][j] % 2 != 0) {
                even_cost++;
                even_cookies[i][j]++;
            } else if ((i + j) % 2 != 0 && cookies[i][j] % 2 == 0) {
                even_cost++;
                even_cookies[i][j]++;
            }
        }
    }

    cout << min(odd_cost, even_cost) << "\n";
    auto it = (odd_cost < even_cost ? odd_cookies : even_cookies);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << it[i][j];
        }
        cout << "\n";
    }
}
