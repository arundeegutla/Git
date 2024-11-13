#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    auto can = [&](ll maxx) -> int {
        ll curSum = 1e18;
        int subs = 0;
        for (int i = 0; i < n; i++) {
            curSum += arr[i];
            if (curSum > maxx) {
                curSum = arr[i];
                subs++;
            }
        }
        return subs <= k;
    };

    ll lo = *(max_element(arr.begin(), arr.end()));
    ll hi = 1e18;
    ll ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;
        if (can(mid)) {
            hi = (ans = mid) - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}