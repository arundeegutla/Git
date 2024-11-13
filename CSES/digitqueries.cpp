#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;

        auto getCount = [&](ll mid) -> ll {
            ll count = 0;

            string s = to_string(mid);
            int len = s.size();

            ll have = 9;
            for (int i = 1; i < len; i++) {
                // this many.
                count += have * i;
                have *= 10;
            }

            have = 0;
            for (int i = 0; i + 1 < len; i++) {
                have *= 10;
                have += 9;
            }

            ll x = mid - have;
            count += len * x;
            return count;
        };

        ll lo = 0;
        ll hi = 1e17;
        ll ans = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (getCount(mid) <= k) {
                lo = (ans = mid) + 1;
            } else {
                hi = mid - 1;
            }
        }

        // cout << getCount(1e17) << "\n";
        ll indx = k - getCount(ans);
        if (indx > 0) {
            string s = to_string(ans + 1);
            cout << s[indx - 1] << "\n";
        } else {
            string s = to_string(ans);
            cout << s.back() << "\n";
        }
    }
}
