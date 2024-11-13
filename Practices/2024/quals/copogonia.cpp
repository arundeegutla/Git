#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int ll

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<pair<int, int>> points(n);
    for (auto& [x, y] : points) {
        cin >> x >> y;
    }

    vector<pair<int, pair<int, int>>> roads(k);
    for (auto& [w, p] : roads) {
        auto& [x, y] = p;
        cin >> x >> y;
        x--, y--;
        cin >> w;
    }

    ll cost = 1e18;
    for (int mask = 0; mask < (1 << k); mask++) {
        // cout << bitset<2>(mask).to_string() << "\n";
        vvi grid(n, vi(n, 1e18));
        for (int i = 0; i < n; i++) {
            grid[i][i] = 0;
            auto [x, y] = points[i];
            auto [xx, yy] = points[(i + 1) % n];
            grid[i][(i + 1) % n] = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
            grid[(i + 1) % n][i] = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
        }

        ll hereCost = 0;
        for (int i = 0; i < k; i++) {
            if ((mask & (1 << i)) == 0) continue;
            auto [w, p] = roads[i];
            hereCost += w;
            auto [from, to] = p;
            auto [x, y] = points[from];
            auto [xx, yy] = points[to];
            grid[from][to] = min(grid[from][to], sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy)));
            grid[to][from] = min(grid[to][from], sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy)));
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] > (grid[i][k] + grid[k][j]))
                        grid[i][j] = (grid[i][k] + grid[k][j]);
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (grid[i][j] == 1e18) {
        //             cout << "oo ";
        //         } else {
        //             cout << grid[i][j] << " ";
        //         }
        //     }
        //     cout << "\n";
        // }

        bool allgood = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                allgood &= grid[i][j] <= m + 0.001;
            }
        }

        if (allgood) {
            cost = min(cost, hereCost);
        }
    }
    cout << cost << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}