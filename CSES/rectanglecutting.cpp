#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[501][501];
int main() {
    int a, b;
    cin >> a >> b;
    for (int r = 0; r <= a; r++) {
        for (int c = 0; c <= b; c++) {
            if (r == c) continue;
            ll minn = 1e12;
            for (int i = 1; i < r; i++) {
                minn = min(minn, memo[i][c] + memo[r - i][c] + 1);
            }
            for (int i = 1; i < c; i++) {
                minn = min(minn, memo[r][i] + memo[r][c - i] + 1);
            }
            memo[r][c] = minn;
        }
    }

    cout << memo[a][b] << "\n";
}