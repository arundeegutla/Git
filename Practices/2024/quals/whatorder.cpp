#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define int ll

void solve() {
    int n, c;
    cin >> n >> c;
    vector<unordered_set<int>> graph(n);
    vector<unordered_set<int>> negGraph(n);
    vector<unordered_set<int>> conseq(n);

    while (c--) {
        int x;
        cin >> x;
        char a, b;
        cin >> a >> b;

        int xa = a - 'A';
        int xb = b - 'A';

        if (x == 1) {
            graph[xa].insert(xb);
            negGraph[xb].insert(xa);
        } else if (x == 2) {
            graph[xb].insert(xa);
            negGraph[xa].insert(xb);
        } else {
            conseq[xa].insert(xb);
            conseq[xb].insert(xa);
        }
    }

    function<int(int, int)> go = [&](int at, int seen) -> int {
        if (bitset<20>(seen).count() == n) return 1;

        int tot = 0;
        for (int i = 0; i < n; i++) {
            if ((seen & (1 << i)) != 0) continue;

            bool good = true;
            for (int k = 0; k < n; k++) {
                if ((seen & (1 << k)) == 0) continue;
                good &= negGraph[i].count(k) == 0;
            }

            if (!good) continue;
            if (conseq[at].count(i)) continue;
            tot += go(i, seen | (1 << i));
        }

        return tot;
    };

    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += go(i, 1 << i);
    }

    cout << tot << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}