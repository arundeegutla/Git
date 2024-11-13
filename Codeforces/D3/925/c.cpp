#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;

    int lNum = arr[0];
    int longestLeft = 0;
    for (auto x : arr) {
        if (x == lNum)
            longestLeft++;
        else
            break;
    }
    reverse(all(arr));
    int rNum = arr[0];
    int longestRight = 0;
    for (auto x : arr) {
        if (x == rNum)
            longestRight++;
        else
            break;
    }

    int need = n - max(longestRight, longestLeft);
    if (lNum == rNum) {
        need = n - (longestLeft + longestRight);
    }

    // cout << n << " " << longestLeft << "\n";

    cout << max(need, 0LL) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}