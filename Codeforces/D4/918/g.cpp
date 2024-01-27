#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> slow(n);
    for (auto& x : slow) cin >> x;

    vector<vector<ll>> dist(n, vector<ll>(n, 1e18));
    //          bike here
    queue<pair<int, int>> q;
    q.push({0, 0});
    for (auto& x : dist[0]) {
        x = 0;
    }

    while (q.size()) {
        auto [bike, at] = q.front();
        q.pop();
        auto d = dist[at][bike];
        bike = min(bike, slow[at]);
        for (auto [to, w] : graph[at]) {
            if (dist[to][bike] > d + (slow[bike] * w)) {
                dist[to][bike] = d + (slow[bike] * w);
                q.push({bike, to});
            }
        }
    }

    cout << *(min_element(dist[n - 1].begin(), dist[n - 1].end())) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while (n--) solve();
}