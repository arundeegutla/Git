#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << c << "\n";
    } else if (b == c) {
        cout << a << "\n";
    } else if (a == c) {
        cout << b << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}