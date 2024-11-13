#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string a, b;
    cin >> a >> b;
    int maxLen = max(a.size(), b.size());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a.resize(maxLen, '0');
    b.resize(maxLen, '0');

    vector<pair<int, int>> ans;

    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        int x = a[i] - '0';
        int y = b[i] - '0';

        int tot = x + y + carry;
        carry = tot / 10;
        ans.push_back({tot % 10, carry});
        cout << tot % 10 << " " << carry << "\n";
    }

    if (carry) {
        cout << carry << " " << 0 << "\n";
    }
}