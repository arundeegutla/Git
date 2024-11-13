#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (auto& x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    auto can = [&](int x) -> bool {
        for (int i = n - 1; i >= 0; i--) {
        }
    };

    int x = 1;
    while (can(x)) x++;

    cout << x << "\n";
}