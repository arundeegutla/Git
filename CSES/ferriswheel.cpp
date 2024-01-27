#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll x;
    cin >> x;

    vector<ll> weight(n);
    for (auto& x : weight) cin >> x;

    sort(weight.begin(), weight.end());

    int numTwos = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (weight[r] + weight[l] > x) {
            r--;
        } else {
            numTwos++;
            l++;
            r--;
        }
    }

    int numOnes = n - (2 * numTwos);

    cout << numTwos + numOnes << "\n";
}