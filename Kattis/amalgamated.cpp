#include <bits/stdc++.h>
using namespace std;

int main() {
    double p, a, b, c, d;
    int n;
    cin >> p >> a >> b >> c >> d >> n;

    auto price = [&](int k) -> double {
        return p * (sin(a * k + b) + cos(c * k + d) + 2);
    };

    double maxx = 0;
    double maxDecline = 0;
    for (int i = 1; i <= n; i++) {
        auto priceHere = price(i);
        maxDecline = max({maxx - priceHere, 0.0, maxDecline});
        maxx = max(maxx, priceHere);
    }
    cout << "\n";

    cout << fixed << setprecision(10) << maxDecline << "\n";
}