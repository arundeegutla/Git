#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    vector<ll> sums;
    auto go1 = [&](int at, ll sum, auto&& go1) -> void {
        if (sum > target) return;
        if (at == n / 2) {
            sums.push_back(sum);
            return;
        }
        go1(at + 1, sum, go1);
        go1(at + 1, sum + arr[at], go1);
    };
    go1(0, 0, go1);

    sort(sums.begin(), sums.end());
    ll tot = 0;
    auto go2 = [&](int at, ll sum, auto&& go2) -> void {
        if (sum > target) return;
        if (at == n) {
            int complement = target - sum;
            if (complement < 0) return;
            auto itrs = equal_range(sums.begin(), sums.end(), complement);
            tot += itrs.second - itrs.first;
            return;
        }
        go2(at + 1, sum, go2);
        go2(at + 1, sum + arr[at], go2);
    };
    go2(n / 2, 0, go2);

    cout << tot << "\n";
}
