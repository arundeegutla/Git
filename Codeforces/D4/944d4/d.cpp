#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
// #define int ll

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int pieces = 0;

    int ones = 0;
    int zeroes = 0;
    int prev = -1;
    bool sorted = false;
    for (int i = 0; i < n; i++) {
        int here = s[i] - '0';
        if (here == prev) continue;
        if (prev == 0 && here == 1)
            sorted = true;
        if (here == 1) {
            ones++;
        } else {
            zeroes++;
        }
        prev = here;
    }

    cout << ones + zeroes - sorted << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}