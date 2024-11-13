#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    for (auto& x : grid)
        cin >> x;

    vvi psum(n + 1, vi(m + 1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            psum[i + 1][j + 1] = psum[i + 1][j] + (grid[i][j] - '0');
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            psum[i + 1][j + 1] += psum[i][j + 1];

    auto getActual = [&](int r1, int c1, int r2, int c2) -> int {
        return (r2 - r1 + 1) * (c2 - c1 + 1);
    };

    auto getSum = [&](int r1, int c1, int r2, int c2) -> int {
        return psum[r2 + 1][c2 + 1] - psum[r2 + 1][c1] - psum[r1][c2 + 1] + psum[r1][c1];
    };

    int maxx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = j; k < m; k++) {
                int lo = i;
                int hi = n - 1;
                int best = -1;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    if (getSum(i, j, mid, k) == getActual(i, j, mid, k)) {
                        lo = (best = mid) + 1;
                    } else {
                        hi = mid - 1;
                    }
                }

                if (best != -1) {
                    maxx = max(maxx, getSum(i, j, best, k));
                }
            }
        }
    }

    cout << maxx << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}