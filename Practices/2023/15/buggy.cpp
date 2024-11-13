#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Info {
    int r, c, at;
};

signed main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& x : grid) cin >> x;
    string s;
    cin >> s;

    pair<int, int> start;
    pair<int, int> exit;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'R') {
                start = {i, j};
            }
            if (grid[i][j] == 'E') {
                exit = {i, j};
            }
        }
    }

    vector<vector<vector<int>>> dist(51, vector<vector<int>>(51, vector<int>(60, 1e18)));

    int D[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    unordered_map<char, int> dirMap;
    dirMap['U'] = 2;
    dirMap['D'] = 3;
    dirMap['L'] = 1;
    dirMap['R'] = 0;

    queue<Info> q;
    dist[start.first][start.second][0] = 0;
    q.push({start.first, start.second, 0});
    while (q.size()) {
        auto [r, c, at] = q.front();
        q.pop();
        auto hereDist = dist[r][c][at];
        // cout << "info: " << r << " " << c << " " << at << " " << hereDist << "\n";
        if (r == exit.first && c == exit.second) continue;

        if (at < s.size()) {
            auto dHere = D[dirMap[s[at]]];
            int nR = r + dHere[0];
            int nC = c + dHere[1];
            if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') {
                nR = r;
                nC = c;
            }
            if (dist[nR][nC][at + 1] > hereDist) {
                q.push({nR, nC, at + 1});
                dist[nR][nC][at + 1] = hereDist;
            }
            // delete
            if (dist[r][c][at + 1] > hereDist + 1) {
                q.push({r, c, at + 1});
                dist[r][c][at + 1] = hereDist + 1;
            }
        }
        for (auto d : D) {
            int nR = r + d[0];
            int nC = c + d[1];
            if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') {
                nR = r;
                nC = c;
            }
            if (dist[nR][nC][at] > hereDist + 1) {
                q.push({nR, nC, at});
                dist[nR][nC][at] = hereDist + 1;
            }
        }
    }

    int minn = 1e18;
    for (int i = 0; i < 60; i++) {
        minn = min(minn, dist[exit.first][exit.second][i]);
    }
    cout << minn << "\n";
}