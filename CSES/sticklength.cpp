#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    ll lo = 0;
    ll hi = *max_element(arr.begin(), arr.end());
    ll ans = 1e18;
    while (lo <= hi) {
        ll mid1 = lo + (hi - lo) / 3;
        ll mid2 = hi - (hi - lo) / 3;

        ll change1 = 0;
        ll change2 = 0;
        for (int i = 0; i < n; i++) {
            change1 += abs(mid1 - arr[i]);
            change2 += abs(mid2 - arr[i]);
        }

        ans = min({ans, change1, change2});
        if (change1 <= change2) {
            hi = mid2 - 1;
        } else {
            lo = mid1 + 1;
        }
    }

    cout << ans << "\n";
}