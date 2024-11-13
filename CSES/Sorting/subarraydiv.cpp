#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    auto getMod = [&](ll num) -> ll {
        num %= n;
        if (num < 0) num += n;
        return num %= n;
    };

    unordered_map<ll, ll> remainder;
    ll count = 0;
    ll sum = 0;
    remainder[0]++;
    for (auto& x : arr) {
        sum += x;
        count += remainder[getMod(sum)];
        remainder[getMod(sum)]++;
    }
    cout << count << "\n";
}