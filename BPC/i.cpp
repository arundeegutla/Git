#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
    ll w, h;
    cin >> w >> h;

    int q;
    cin >> q;

    unordered_set<int> row;
    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    while (q--) {
        int x, y;
        cin >> x >> y;
        char c;
        cin >> c;

        if (c == 'B') {
            row.insert(x);
            col.insert(y);
            diag1.insert(x + y);
            diag2.insert(x - y);

        } else {
            if (row.find(x) != row.end() || col.find(y) != col.end() || diag1.find(x + y) != diag1.end() || diag2.find(x - y) != diag2.end()) {
                cout << "ATTACK\n";
                return 0;
            }
        }
    }

    cout << "SAFE\n";
}