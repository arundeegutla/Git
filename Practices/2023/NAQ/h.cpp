#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ll n, k, p;
    cin >> n >> k >> p;

    set<ll> factors;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.insert(n / i);
            factors.insert(i);
        }
    }
    factors.insert(n);

    vector<ll> took;
    for (auto x : factors) {
        if ((n / x) <= p && x <= k) {
            took.push_back(x);
            // cout << n << "/" << x << " = " << (n / x) << "\n";
        }
    }

    cout << took.size() << "\n";

    for (auto x : took) {
        cout << x << "\n";
    }
}