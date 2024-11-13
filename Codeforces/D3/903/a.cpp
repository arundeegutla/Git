#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    int itr = 0;
    while (itr <= 10) {
        if (x.find(s) != x.npos) {
            cout << itr << "\n";
            return;
        }
        x += x;
        itr++;
    }
    cout << -1 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}