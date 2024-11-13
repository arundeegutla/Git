#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> water(n);
    for (auto& x : water) {
        cin >> x;
        sum += x;
    }

    int oneCan = sum / n;

    int have = 0;
    for (auto x : water) {
        if (x < oneCan) {
            int need = oneCan - x;
            if (have >= need) {
                have -= need;
            } else {
                cout << "NO\n";
                return;
            }
        } else {
            have += x - oneCan;
        }
    }
    cout << "YES\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}