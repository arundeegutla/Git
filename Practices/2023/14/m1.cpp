#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

int main() {
    int nc;
    cin >> nc;

    while (nc--) {
        ld w, g, h, r;
        cin >> w >> g >> h >> r;
        auto f = [&](ld mid) -> ld {
            return sqrt(mid * mid + (g - r) * (g - r)) + sqrt((w - mid) * (w - mid) + (h - r) * (h - r));
        };
        cout << fixed << setprecision(10) << sqrt(w * w + (h - g) * (h - g)) << " ";
        ld l1 = 0, r1 = w;
        for (int i = 0; i < 200; i++) {
            ld m1 = l1 + (r1 - l1) / 3.0;
            ld m2 = r1 - (r1 - l1) / 3.0;
            ld f1 = f(m1);
            ld f2 = f(m2);
            if (f1 >= f2)
                l1 = m1;
            else
                r1 = m2;
        }
        cout << f(l1) << "\n";
    }
}