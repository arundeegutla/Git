#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    vector<vector<bool>> seen(n, vector<bool>(m));
    function<void(int, int)> go;
    int D[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    go = [&](int r, int c) -> void {
        if (r < 0 || r >= n || c < 0 || c >= m || seen[r][c] || grid[r][c] == 'W') return;
        seen[r][c] = true;
        for (auto d : D) {
            int nR = r + d[0];
            int nC = c + d[1];
            go(nR, nC);
        }
    };

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'L' && !seen[i][j]) {
                go(i, j);
                count++;
            }
        }
    }
    cout << count << "\n";
}