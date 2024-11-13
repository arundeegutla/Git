#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[(int)1e5 + 1][200];
int main() {
    memset(memo, -1, sizeof(memo));
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    int MOD = 1e9 + 7;

    function<ll(int, int)> go;

    go = [&](int at, int prev) -> ll {
        if ((prev < 1 && prev != -1) || prev > m) return 0;
        if (at == n) return 1;

        auto& ans = memo[at][prev + 1];
        if (ans != -1) return ans;

        ll ways = 0;
        if (arr[at] == 0) {
            if (prev == -1) {
                for (int i = 1; i <= m; i++) {
                    ways += go(at + 1, i);
                    ways %= MOD;
                }
            } else {
                for (int i = -1; i <= 1; i++) {
                    ways += go(at + 1, prev + i);
                    ways %= MOD;
                }
            }
        } else {
            if (at != 0 && abs(arr[at] - prev) > 1) {
            } else {
                ways += go(at + 1, arr[at]);
                ways %= MOD;
            }
        }

        return ans = ways;
    };

    cout << go(0, -1) << "\n";
}