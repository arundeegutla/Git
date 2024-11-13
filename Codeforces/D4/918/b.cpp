#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;

    ll numSquares = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        numSquares += x;
    }

    ll ans = sqrt((ld)numSquares);

    if (ans * ans == numSquares) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}