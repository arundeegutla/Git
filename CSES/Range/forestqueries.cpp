#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    vector<vector<int>> psum(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            psum[i + 1][j + 1] = grid[i][j] == '*';
            psum[i + 1][j + 1] += psum[i + 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            psum[i + 1][j + 1] += psum[i][j + 1];
        }
    }

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << psum[r2][c2] - psum[r2][c1 - 1] - psum[r1 - 1][c2] + psum[r1 - 1][c1 - 1] << "\n";
    }
}