#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    cin >> P;

    vector<int> gols_p(P);

    for (int i = 0; i < P; i++) {
        cin >> gols_p[i];
    }

    int C;
    cin >> C;

    vector<int> gols_c(C);

    for (int i = 0; i < C; i++) {
        cin >> gols_c[i];
    }

    cout << "0 x 0" << "\n";
    int p_pointer = 0;
    int c_pointer = 0;

    while (p_pointer < P && c_pointer < C) {
        if (gols_p[p_pointer] < gols_c[c_pointer]) {
            p_pointer++;
        } else {
            c_pointer++;
        }

        cout << p_pointer << ' ' << c_pointer << '\n';
    }

    while (p_pointer < P) {
        p_pointer++;
        cout << p_pointer << ' ' << c_pointer << '\n';
    }

    while (c_pointer < C) {
        c_pointer++;
        cout << p_pointer << ' ' << c_pointer << '\n';
    }  
    return 0;
}