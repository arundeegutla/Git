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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b) {
        swap(a, b);
    }

    int seen = 0;
    for (int i = a; i <= b; i++) {
        seen += i == c || i == d;
    }

    if (seen == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}