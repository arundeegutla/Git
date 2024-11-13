#include <bits/stdc++.h>
using namespace std;
#define int long long

int memo[(int)1e6 + 1];
signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    for (int need = 1; need <= k; need++) {
        int count = 1e18;
        for (auto x : arr)
            count = min(count, (need - x >= 0 ? memo[need - x] : (int)1e18) + 1);
        memo[need] = count;
    }

    cout << (memo[k] == 1e18 ? -1 : memo[k]) << "\n";
}