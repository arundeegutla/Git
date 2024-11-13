#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;

    unordered_map<ll, ll> prefx;
    ll count = 0;
    ll sum = 0;
    prefx[0]++;
    for (auto x : arr) {
        sum += x;
        count += prefx[sum - t];
        prefx[sum]++;
    }
    cout << count << "\n";
}