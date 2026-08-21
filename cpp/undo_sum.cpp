#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            numbers.pop_back();
        } else {
            numbers.push_back(x);
        }
    }

    int sum = 0;

    for (int n : numbers) {
        sum += n;
    }

    cout << sum << endl;

    return 0;
}