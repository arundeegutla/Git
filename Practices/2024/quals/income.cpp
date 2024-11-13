#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vector<ll> ppl(n);
    for (auto& x : ppl) cin >> x;
    sort(ppl.rbegin(), ppl.rend());

    ll sum = accumulate(ppl.begin(), ppl.end(), 0LL);
    double ans = 0;
    ll run = 0;
    for (int i = 0; i < n; i++) {
        run += ppl[i];
        ans = max(ans, 100 * ((run / (sum * 1.0)) - ((i + 1) / (n * 1.0))));
    }

    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}