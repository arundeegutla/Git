#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    ll tot = accumulate(arr.begin(), arr.end(), 0LL);
    ll minn = 1e18;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        minn = min(minn, abs((tot - sum) - sum));
    }
    cout << minn << "\n";
}