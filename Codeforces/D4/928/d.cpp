#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int long long

void solve() {
    int n;
    cin >> n;

    int count = 0;
    map<string, int> have;
    while (n--) {
        int x;
        cin >> x;
        string other = bitset<31>(x).to_string();
        for (auto& x : other) {
            if (x == '0') {
                x = '1';
            } else {
                x = '0';
            }
        }
        if (have[other]) {
            have[other]--;
            count++;
        } else {
            string here = bitset<31>(x).to_string();
            have[here]++;
        }
    }

    for (auto [_, v] : have) {
        count += v;
    }
    cout << count << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}