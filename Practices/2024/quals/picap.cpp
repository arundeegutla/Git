#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> names(n);
    for (auto& x : names) cin >> x;

    auto can = [&](ll line) -> bool {
        int lineNum = 1;
        int curLine = 0;
        for (auto x : names) {
            if (lineNum > k) return false;
            if (curLine + x + (curLine != 0) > line) {
                lineNum++;
                if (lineNum > k) return false;
                curLine = x;
            } else {
                curLine += x + (curLine != 0);
            }
        }
        return true;
    };

    ll lo = 0;
    ll hi = 1e18;
    ll ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;

        if (can(mid)) {
            hi = (ans = mid) - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}