#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    queue<pair<int, int>> q;
    vector<vector<int>> monstDist(n, vector<int>(m, 1e18));

    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            }
            if (grid[i][j] == 'M') {
                q.push({i, j});
                monstDist[i][j] = 0;
            }
        }
    }

    int D[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int DR[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();
        auto dHere = monstDist[r][c];
        for (auto d : D) {
            int nR = r + d[0];
            int nC = c + d[1];
            if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;
            if (monstDist[nR][nC] > dHere + 1) {
                monstDist[nR][nC] = dHere + 1;
                q.push({nR, nC});
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, 1e18));
    q.push(start);
    dist[start.first][start.second] = 0;
    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();
        auto dHere = dist[r][c];
        for (auto d : D) {
            int nR = r + d[0];
            int nC = c + d[1];
            if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;
            if (dist[nR][nC] > dHere + 1) {
                dist[nR][nC] = dHere + 1;
                q.push({nR, nC});
            }
        }
    }

    vector<vector<int>> path(n, vector<int>(m, -1));
    pair<int, int> end = {-1, -1};
    q.push(start);
    path[start.first][start.second] = -2;
    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();
        if (r == 0 || c == 0 || r == n - 1 || c == m - 1) {
            end = {r, c};
            break;
        }
        auto dHere = dist[r][c];
        for (int i = 0; i < 4; i++) {
            auto d = D[i];
            int nR = r + d[0];
            int nC = c + d[1];
            if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;
            if (dist[nR][nC] < monstDist[nR][nC] && path[nR][nC] == -1) {
                q.push({nR, nC});
                path[nR][nC] = i;
            }
        }
    }

    if (end.first == -1) {
        cout << "NO\n";
        return 0;
    }

    string dir = "RLUD";
    string p;
    while (path[end.first][end.second] != -2) {
        int x = path[end.first][end.second];
        p.push_back(dir[x]);
        end.first += DR[x][0];
        end.second += DR[x][1];
    }

    cout << "YES\n";
    cout << p.size() << "\n";
    reverse(p.begin(), p.end());
    cout << p << "\n";
}