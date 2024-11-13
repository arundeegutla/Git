#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[(int)1e6 + 1];
int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;

    function<ll(int)> go;
    go = [&](int num) -> ll {
        if (num == 0) return 0;
        auto& ans = memo[num];
        if (ans != -1) {
            return ans;
        }
        string s = to_string(num);
        ll minn = 1e10;
        for (auto& c : s) {
            if (c == '0') continue;
            minn = min(minn, 1 + go(num - (c - '0')));
        }
        return ans = minn;
    };

    cout << go(n) << "\n";
}