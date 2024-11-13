#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

signed main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    function<int()> getTaxi;
    getTaxi = [&]() -> int {
        vector<pair<int, int>> D = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {0, 2}, {0, -2}, {-2, 0}, {2, 0}};
        vvi dist(n, vi(n, 1e18));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 0;

        while (q.size()) {
            auto here = q.front();
            q.pop();
            int hereDist = dist[here.first][here.second];
            if (here.first == n - 1 && here.second == n - 1) {
                continue;
            }
            for (int i = 0; i < D.size(); i++) {
                int nR = here.first + D[i].first;
                int nC = here.second + D[i].second;
                if (nR < 0 || nR >= n || nC < 0 || nC >= n || grid[nR][nC] == 'X') continue;
                if (i >= 4) {
                    int checkR = D[i - 4].first + here.first;
                    int checkC = D[i - 4].second + here.second;
                    if (checkR < 0 || checkR >= n || checkC < 0 || checkC >= n || grid[checkR][checkC] == 'X') continue;
                }
                int nextDist = hereDist + 10;
                if (dist[nR][nC] > nextDist) {
                    dist[nR][nC] = nextDist;
                    q.push({nR, nC});
                }
            }
        }

        return dist[n - 1][n - 1];
    };

    function<int()> getSpider;
    getSpider = [&]() -> int {
        vector<pair<int, int>> D = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vvi dist(n, vi(n, 1e18));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 0;

        while (q.size()) {
            auto here = q.front();
            q.pop();
            int hereDist = dist[here.first][here.second];
            if (here.first == n - 1 && here.second == n - 1) {
                continue;
            }
            for (int i = 0; i < D.size(); i++) {
                int nR = here.first + D[i].first;
                int nC = here.second + D[i].second;
                if (nR < 0 || nR >= n || nC < 0 || nC >= n || grid[nR][nC] == 'X') continue;
                int nextDist = hereDist + (i >= 4 ? 15 : 10);
                if (dist[nR][nC] > nextDist) {
                    dist[nR][nC] = nextDist;
                    q.push({nR, nC});
                }
            }
        }

        return dist[n - 1][n - 1];
    };

    int taxiDist = getTaxi();
    int spiderDist = getSpider();

    // cout << taxiDist << " " << spiderDist << "\n";

    if (taxiDist < spiderDist) {
        cout << "taxicab\n";
    } else if (spiderDist < taxiDist) {
        cout << "spider\n";

    } else {
        cout << "tie\n";
    }
}