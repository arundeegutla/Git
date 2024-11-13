#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    int p, d;
    cin >> p >> d;
    vector<pair<int, int>> district(d);
    while (p--) {
        int dis;
        cin >> dis;
        dis--;
        int a, b;
        cin >> a >> b;
        district[dis].first += a;
        district[dis].second += b;
    }

    int wA = 0;
    int wB = 0;
    int tot = 0;
    for (auto [a, b] : district) {
        tot += a + b;
        int half = ((a + b) / 2) + 1;
        if (a > b) {
            cout << "A " << (a - half) << " " << b << "\n";
            wA += a - half;
            wB += b;
        } else {
            cout << "B " << (a) << " " << (b - half) << "\n";
            wA += a;
            wB += b - half;
        }
    }

    cout << fixed << setprecision(10) << abs(wA - wB) / (tot * 1.0) << "\n";
}