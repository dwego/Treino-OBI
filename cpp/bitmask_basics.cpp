#include <bits/stdc++.h>
using namespace std;

int n, l, r, x;
int v[20];
long long resp;

// learn bitmask (simple)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l >> r >> x;


    return 0;
}


void ligar(int &n, int j)
{
	n = n | (1 << j);
}

bool ligado(int n, int j)
{
  if (n & (1 << j)) return true;
  else return false;
}
