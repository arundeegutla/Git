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
    string s;
    cin >> s;

    unordered_set<char> V = {'a', 'e'};

    int i = 0;
    while (i + 3 < n) {
        if (V.count(s[i + 3])) {
            cout << s[i] << s[i + 1] << '.';
            i += 2;
        } else {
            cout << s[i] << s[i + 1] << s[i + 2] << '.';
            i += 3;
        }
    }

    while (i < n) cout << s[i++];

    cout
        << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}