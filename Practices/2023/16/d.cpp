#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int a, b;
    cin >> a >> b;
    int ops = 0;

    while (a != b) {
        if (a < b) {
            ops += b - a;
            a = b;
        } else {
            if ((a % 2) == 0) {
                a /= 2;
            } else {
                a++;
            }
            ops++;
        }
    }
    cout << ops << "\n";
}