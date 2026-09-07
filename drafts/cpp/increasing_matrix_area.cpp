#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matriz(N, vector<int>(M));
    vector<vector<int>> ate(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        ate[i][M - 1] = M - 1;
        for (int j = M - 2; j >= 0; j--) {
            if (matriz[i][j] < matriz[i][j + 1]) {
                ate[i][j] = ate[i][j + 1];
            } else {
                ate[i][j] = j;
            }
        }
    }


    int maiorArea = 0;

    for (int left = 0; left < M; left++) {
        for (int right = left; right < M; right++) {
            int altura = 0;

            for (int linha = 0; linha < N; linha++) {
                if (ate[linha][left < right]) {
                    altura = 0;
                    continue;
                }

                if (altura == 0) {
                    altura = 1;
                }
                else if (matriz[linha - 1][right] < matriz[linha][left]) {
                    altura++;
                }
                else {
                    altura = 1;
                }

                int largura = right - left + 1;
                maiorArea = max(maiorArea, largura * altura);

            }
        }
    }

}
