#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

vector<int> ans(2e5 + 10);
void solve() {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    for (int i = 1; i < (2e5 + 1); i++) {
        int k = i;
        while (k > 0) {
            ans[i] += k % 10;
            k /= 10;
        }
        ans[i] += ans[i - 1];
    }

    int n;
    cin >> n;
    while (n--) solve();
}