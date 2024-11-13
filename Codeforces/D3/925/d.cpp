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
    int n, x, y;
    cin >> n >> x >> y;
    map<int, int> freq;
    vector<int> arr(n);
    int totPairs = 0;

    for (auto& t : arr) {
        cin >> t;
        for (auto [k, v] : freq) {
            if ((k + t) % x != 0) continue;
            int val = k - t;
            if (val < 0) val *= -1;
            if (val % y != 0) continue;
            totPairs += v;
        }

        freq[t]++;
    }

    cout << totPairs << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}