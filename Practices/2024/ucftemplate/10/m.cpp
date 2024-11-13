#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    auto calc = [&](int start) -> int {
        int tot = 0;
        for (int i = 0; i < n; i++)
            tot += abs(arr[i] - (start + i));
        return tot;
    };

    int lo = -4e5;
    int hi = 4e5;
    int ans = -1e9;

    while (lo <= hi) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;

        if (calc(mid1) < calc(mid2)) {
            ans = mid1;
            hi = mid2 - 1;
        } else {
            ans = mid2;
            lo = mid1 + 1;
        }
    }

    cout << calc(ans) << "\n";
}
