#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int long long

void solveCheck(int n) {
    set<int> done;
    int j = 1;
    while (done.size() != n) {
        cout << j << ": ";
        int count = 0;
        for (int i = 1; i <= n; i += 2) {
            if (i * j > n) continue;
            if (done.find(i * j) == done.end()) {
                done.insert(i * j);
                // cout << i * j << " ";
                count++;
            }
        }
        cout << " :" << count << "\n";
        j *= 2;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    // solveCheck(n);
    int have = 0;
    int prev = n;
    bool flag = true;
    int power = 1;
    for (; power <= n && have < k; power *= 2) {
        if (prev % 2) {
            prev = (prev + flag) / 2;
            // cout << power << ": : " << prev << " " << flag << "\n";
            have += prev;
            if (have >= k) {
                have -= prev;
                break;
            }
            flag = !flag;
        } else {
            prev = prev / 2;
            // cout << power << ": : " << prev << "\n";

            have += prev;
            if (have >= k) {
                have -= prev;
                break;
            }
        }
    }

    have++;
    // cout << have << " p:" << power << "\n";
    cout << power + ((power * 2) * (k - have)) << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}