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
    unordered_set<string> hset;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        hset.insert(s);
    }

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        if (hset.count(s)) {
            cout << 1 << "\n";
        } else {
            bool done = false;
            for (int i = 1; i < s.size(); i++) {
                string a = s.substr(0, i);
                string b = s.substr(i);
                // cout << a << " " << b << "\n";
                if (hset.count(a) && hset.count(b)) {
                    cout << 2 << "\n";
                    done = true;
                    break;
                }
            }
            if (!done)
                cout << 0 << "\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}