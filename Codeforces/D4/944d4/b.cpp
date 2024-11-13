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
    bool allSame = true;
    for (auto c : s) {
        allSame &= c == s[0];
    }
    if (allSame) {
        cout << "NO\n";
        return;
    }

    for (auto& x : s) {
        if (x != s[0]) {
            cout << "YES\n";
            swap(x, s[0]);
            cout << s << "\n";
            return;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}