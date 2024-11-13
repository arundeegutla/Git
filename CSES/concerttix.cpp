#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> tix;
    while (n--) {
        int x;
        cin >> x;
        tix[x]++;
    }

    while (m--) {
        int c;
        cin >> c;

        auto itr = tix.upper_bound(c);
        if (itr != tix.begin()) {
            itr--;
            int x = (*itr).first;
            cout << x << "\n";
            tix[x]--;
            if (tix[x] == 0) {
                tix.erase(x);
            }
        } else {
            cout << -1 << "\n";
        }
    }
}