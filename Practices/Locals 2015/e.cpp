#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979

void solve() {
    int s, r;
    cin >> s >> r;
    if (2 * r <= s) {
        cout << fixed << setprecision(2) << PI * r * r << "\n";
        return;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}