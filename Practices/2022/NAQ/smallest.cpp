#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int a, b, c;
    cin >> a >> b >> c;

    auto get = [&](int l, int r) -> int {
        int minn = 1e18;
        if (l + r >= 0) minn = min(minn, l + r);
        if (l - r >= 0) minn = min(minn, l - r);
        if (l * r >= 0) minn = min(minn, l * r);
        if (l % r == 0 && l / r >= 0) minn = min(minn, l / r);
        return minn;
    };

    int minn = 1e18;
    minn = min(minn, get(a + b, c));
    minn = min(minn, get(a - b, c));
    minn = min(minn, get(a * b, c));
    if (a % b == 0) minn = min(minn, get(a / b, c));

    cout << minn << "\n";
}