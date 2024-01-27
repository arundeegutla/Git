#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        cout << ((max(a, b) > 2 * min(a, b) || (a + b) % 3) ? "NO\n" : "YES\n");
    }
}