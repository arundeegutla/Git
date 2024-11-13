#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (auto& x : weights) cin >> x;

    vector<int> memo(1 << (n + 1), -1);
    function<int(int)> go;
    go = [&](int taken) -> int {
        cout << bitset<20>(taken).to_string() << "\n";
        if (bitset<21>(taken).count() == n) return 0;

        auto& ans = memo[taken];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }
        vector<int> nextMasks;
        auto getMasks = [&](int at, int mask, int sum, auto&& getMasks) -> void {
            if (at == n) {
                if (bitset<21>(mask).count() >= 1)
                    nextMasks.push_back(mask);
                return;
            }
            getMasks(at + 1, mask, sum, getMasks);
            if ((taken & (1 << at)) == 0 && sum + weights[at] <= x) {
                getMasks(at + 1, mask | (1 << at), sum + weights[at], getMasks);
            }
        };
        getMasks(0, 0, 0, getMasks);

        int minn = 1e18;
        for (auto mask : nextMasks)
            minn = min(minn, go(taken | mask) + 1);
        return ans = minn;
    };

    cout << go(0) << "\n";
}