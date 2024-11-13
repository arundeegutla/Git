
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    int n, w;
    cin >> n >> w;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    using pii = pair<int, ll>;
    auto add = [&](pii before, int x) -> pii {
        before.second += x;
        if (before.second > w) {
            before.second = x;
            before.first++;
        }
        return before;
    };

    vector<pii> memo(1 << (n + 1), {-1, -1});
    function<pii(int)> go = [&](int mask) -> pii {
        if (bitset<21>(mask).count() == n) return {1, 0};
        auto& ans = memo[mask];
        if (ans.first != -1) return ans;
        pair<int, ll> best = {1e18, 1e18};
        for (int i = 0; i < n; i++)
            if ((mask & (1 << i)) == 0)
                best = min(best, add(go(mask | (1 << i)), arr[i]));
        return ans = best;
    };

    cout << go(0).first << "\n";
}