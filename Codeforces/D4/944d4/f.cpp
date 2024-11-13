#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int ll

vector<ll> square(1e6);
void solve() {
    ll r;
    cin >> r;

    ll minBound = r * r;
    ll maxBound = (r + 1) * (r + 1);

    ll tot = 0;

    for (ll x = 0; minBound - (x * x) >= 0; x++) {
        ll lowerNeed = minBound - (x * x);
        ll higherNeed = maxBound - (x * x);

        auto itr = lower_bound(square.begin(), square.end(), lowerNeed);
        auto itr2 = lower_bound(square.begin(), square.end(), higherNeed);

        if (x == 0) {
            tot += ((itr2) - (itr)) * 2LL;
            continue;
        }

        if ((*itr) == 0) {
            tot += 2LL;
            itr++;
        }

        if (itr < itr2) {
            tot += ((itr2) - (itr)) * 4LL;
        }
    }

    cout << tot << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    for (ll i = 0; i < 1e6; i++)
        square[i] = i * i;
    int n;
    cin >> n;
    while (n--) solve();
}