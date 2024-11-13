#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[1001][1001];
int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;

    int MOD = 1e9 + 7;
    function<ll(int, int)> go;
    go = [&](int r, int c) -> ll {
        if (r >= n || c >= n) return 0;
        if (grid[r][c] == '*') return 0;
        if (r == n - 1 && c == n - 1) return 1;

        auto& ans = memo[r][c];
        if (ans != -1) return ans;
        ll ways = 0;
        ways += go(r + 1, c);
        ways %= MOD;
        ways += go(r, c + 1);
        ways %= MOD;
        return ans = ways;
    };

    cout << go(0, 0) << "\n";
}