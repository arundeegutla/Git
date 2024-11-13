#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Grid #" << i << ": ";
        ll d, x;
        cin >> d >> x;
        int numCells = ((x - 1) * (x - 1)) + 1;
        if (d > numCells) {
            cout << "impossible\n\n";
            continue;
        }
        cout << (x + (x - 2)) * d << "\n\n";
    }
}