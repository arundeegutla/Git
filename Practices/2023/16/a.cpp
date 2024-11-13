#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    auto go = [&](int t) -> int {
        int sumLeft = 0;
        int sumRight = 0;
        for (auto x : arr) {
            if (x < t) {
                sumLeft += x;
            } else if (x > t) {
                sumRight += x;
            }
        }
        return sumLeft - sumRight;
    };

    int lo = 0;
    int hi = 1e6;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int which = go(mid);
        if (which == 0) {
            hi = (ans = mid) - 1;
        } else if (which < 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    assert(ans != -1);
    cout << ans << "\n";
}