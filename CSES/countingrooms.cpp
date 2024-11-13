#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    int D[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> seen(n, vector<bool>(m));
    function<void(int, int)> go;
    go = [&](int r, int c) -> void {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '#' || seen[r][c]) return;
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
            if (!seen[i][j] && grid[i][j] == '.') {
                count++;
                go(i, j);
            }
        }
    }

    cout << count << "\n";
}