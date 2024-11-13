#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
ll memo[1001][1 << 12];

signed main() {
    memset(memo, -1, sizeof(memo));
    int n, m;
    cin >> n >> m;

    int MOD = 1e9 + 7;
    function<ll(int, int)> go;
    go = [&](int at, int rowBefore) -> ll {
        if (at == m)
            return (bitset<20>(rowBefore).count() == n);

        auto& ans = memo[at][rowBefore + 1];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }

        vector<int> nextMasks;
        auto getMasks = [&](int i, int mask, auto&& getMasks) -> void {
            if (i > n) return;
            if (i == n) {
                nextMasks.push_back(mask);
                return;
            }
            if ((rowBefore & (1 << i)) == 0) {
                getMasks(i + 1, mask | (1 << i), getMasks);
                return;
            }
            if ((rowBefore & (3 << i)) == (3 << i))
                getMasks(i + 2, mask | (3 << i), getMasks);
            getMasks(i + 1, mask, getMasks);
        };
        getMasks(0, 0, getMasks);

        ll ways = 0;
        for (auto nextMask : nextMasks) {
            ways += go(at + 1, nextMask);
            ways %= MOD;
        }
        return ans = ways;
    };

    cout << go(0, -1) << "\n";
}