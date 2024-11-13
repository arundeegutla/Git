#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[20][11][2];

int main() {
    ll a, b;
    cin >> a >> b;
    memset(memo, -1, sizeof(memo));

    function<ll(int, int, bool, string&)> go;
    go = [&](int at, int prev, bool tight, string& s) -> ll {
        if (at == s.size()) {
            return 1;
        }
        auto& ans = memo[at][prev + 1][tight];
        if (ans != -1) {
            // cout << "memo!\n";
            return ans;
        }
        int ub = tight ? (s[at] - '0') : 9;
        ll ways = prev == -1 ? go(at + 1, prev, tight, s) : 0;
        for (int i = 0; i <= ub; i++)
            if (i != prev)
                ways += go(at + 1, i, tight && i == ub, s);
        return ans = ways;
    };

    string x = to_string(b);
    reverse(x.begin(), x.end());
    x.resize(19, '0');
    reverse(x.begin(), x.end());

    string y = to_string(a - 1);
    reverse(y.begin(), y.end());
    y.resize(19, '0');
    reverse(y.begin(), y.end());

    b = go(0, -1, true, x);
    memset(memo, -1, sizeof(memo));
    a = (a == 0 ? 0 : go(0, -1, true, y));
    cout << b - a << "\n";
}