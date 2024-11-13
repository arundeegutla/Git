#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    vector<string> grid(7);
    for (auto& x : grid) cin >> x;
    vector<vector<int>> connected(7, vector<int>(7, 0));

    int D[][2] = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (grid[i][j] != 'B') continue;
            bool diag = true;
            for (auto d : D) {
                int nR = i + d[0];
                int nC = j + d[1];
                diag &= nR >= 0 && nR < 7 && nC >= 0 && nC < 7 && grid[nR][nC] == 'B';
            }
            if (diag) {
                connected[i][j]++;
                for (auto d : D) {
                    int nR = i + d[0];
                    int nC = j + d[1];
                    connected[nR][nC]++;
                }
            }
        }
    }

    auto process = [&](int r, int c) -> void {
        connected[r][c]--;
        for (auto d : D) {
            int nR = r + d[0];
            int nC = c + d[1];
            connected[nR][nC]--;
        }
    };

    int count = 0;
    while (true) {
        int maxx = 0;
        for (auto& x : connected) {
            maxx = max(maxx, *max_element(x.begin(), x.end()));
        }
        assert(maxx >= 0);
        if (maxx == 0) break;

        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (connected[i][j] != maxx) continue;
                for (auto d : D) {
                    int nR = i + d[0];
                    int nC = j + d[1];
                    if (nR < 0 || nR >= 7 || nC < 0 || nC >= 7 || connected[nR][nC] == 0) continue;
                    process(nR, nC);
                }
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}