#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    int n;
    cin >> n;
    while (n--) {
        ld w, g, h, r;
        cin >> w >> g >> h >> r;

        auto getLen = [&](ld mid) -> ld {
            ld lenLeft = sqrtl((mid * mid) + ((r - g) * (r - g)));
            ld lenRight = sqrtl(((w - mid) * (w - mid)) + ((h - r) * (h - r)));
            return lenLeft + lenRight;
        };

        auto getDiff = [&](ld mid) -> ld {
            // tan x = o/a
            ld angleLeft = atan((g - r) / mid);
            ld angleRight = atan((h - r) / (w - mid));
            return abs(angleLeft - angleRight);
        };

        // √(x-x)^2 + (y-y)^2
        ld minLength = sqrtl((w * w) + ((h - g) * (h - g)));

        ld lo = 0;
        ld hi = w;
        ld bestMid = 1e10;
        for (int i = 0; i < 100; i++) {
            ld mid1 = lo + (hi - lo) / 3;
            ld mid2 = hi - (hi - lo) / 3;

            ld diff1 = getDiff(mid1);
            ld diff2 = getDiff(mid2);

            if (diff1 <= diff2) {
                hi = mid2;
                bestMid = mid2;
            } else {
                lo = mid1;
                bestMid = mid1;
            }
        }

        cout << fixed << setprecision(10) << minLength << " " << getLen(bestMid) << "\n";
        // cout << getDiff(bestMid) << "\n";
    }
}