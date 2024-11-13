#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i + 1 < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i + 1);
    }

    vector<int> numLeafs(n);

    function<int(int)> go = [&](int at) -> int {
        if (adj[at].size() == 0) return numLeafs[at] = 1;
        int count = 0;
        for (auto e : adj[at])
            count += go(e);
        return numLeafs[at] = count;
    };
    go(0);

    sort(numLeafs.begin(), numLeafs.end());
    for (auto x : numLeafs) cout << x << " ";
    cout << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
    return 0;
}