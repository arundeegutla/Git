#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    map<pair<int, int>, char> D;
    D[{0, 1}] = 'R';
    D[{0, -1}] = 'L';
    D[{1, 0}] = 'D';
    D[{-1, 0}] = 'U';

    map<char, pair<int, int>> CTOD;
    CTOD['L'] = {0, 1};
    CTOD['R'] = {0, -1};
    CTOD['U'] = {1, 0};
    CTOD['D'] = {-1, 0};

    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }
    }

    vector<vector<pair<int, char>>> dist(n, vector<pair<int, char>>(m, {1e9, '-'}));
    dist[start.first][start.second] = {0, '-'};

    queue<pair<int, int>> q;
    q.push(start);

    while (q.size()) {
        auto& [r, c] = q.front();
        q.pop();
        auto& [distHere, pathTook] = dist[r][c];
        for (auto [d, x] : D) {
            int nR = r + d.first;
            int nC = c + d.second;
            if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;

            pair<int, char> move = {distHere + 1, x};

            if (dist[nR][nC] > move) {
                dist[nR][nC] = move;
                q.push({nR, nC});
            }
        }
    }

    auto& [d, _] = dist[end.first][end.second];

    if (d == 1e9) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    string path = "";
    int r = end.first;
    int c = end.second;
    while (dist[r][c].second != '-') {
        char x = dist[r][c].second;
        path += x;
        r += CTOD[x].first;
        c += CTOD[x].second;
    }
    reverse(path.begin(), path.end());
    cout << path.size() << "\n";
    cout << path << "\n";
}
