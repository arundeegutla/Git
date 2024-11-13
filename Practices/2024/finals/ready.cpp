#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ready(n + 1);
    while(m--) {
        int p, x;
        cin >> p >> x;
        if(x == 3) continue;
        ready[p] |= (1 << x);
    }

    for(int i = 1; i <= n; i++) {
        if(bitset<20>(ready[i]).count() >= 2) {
            cout << i << "\n";
        }
    }
}