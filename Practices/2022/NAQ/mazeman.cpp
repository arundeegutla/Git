#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    string temp;
    getline(cin, temp);
    vector<string> grid(n);
    for (auto& x : grid) {
        getline(cin, x);
    }

    int total = 0;
    for (auto arr : grid) {
        for (auto x : arr) total += x == '.';
    }

    int D[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto go = [&](int i, int j) -> int {
        int count = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (q.size()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto d : D) {
                int nR = r + d[0];
                int nC = c + d[1];
                if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == 'X' || grid[nR][nC] == '-' || (grid[nR][nC] >= 'A' && grid[nR][nC] <= 'W')) continue;
                if (grid[nR][nC] == '.') count++;
                grid[nR][nC] = '-';
                q.push({nR, nC});
            }
        }
        return count;
    };

    int numPlayers = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] >= 'A' && grid[i][j] <= 'W') {
                int here = go(i, j);
                total -= here;
                numPlayers += here != 0;
            }
        }
    }

    cout << numPlayers << " " << total << "\n";
}