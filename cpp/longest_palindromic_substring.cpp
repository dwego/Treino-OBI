#include <iostream>
using namespace std;

int main() {
    string cadeia;
    cin >> cadeia;

    int ans = 0;
    int value = 0;

    for (int l = 0; l < cadeia.length(); l++) {
        for (int r = l; r < cadeia.length(); r++) {
            string semicadeia = cadeia.substr(l, r - l + 1);
            string copia = semicadeia;
            reverse(semicadeia.begin(), semicadeia.end());

            cout << semicadeia << " " << copia << endl;

            if (copia == semicadeia) {
                value = semicadeia.length();
            }
            ans = max(ans, value);
        }
    }

    cout << ans << endl;
}
