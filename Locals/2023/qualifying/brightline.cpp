#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> graph(n);
    while (m--) {
        ll s, e, a;
        char t;
        cin >> s >> e >> t >> a;
        s--, e--;
        if (t == 'r') a *= -1LL;
        graph[s].push_back({e, a});
    }

    queue<int> q;
    q.push(0);
    vector<ll> dist(n, 1e18);
    dist[0] = 0;

    while (q.size()) {
        int here = q.front();
        q.pop();
        int d = dist[here];
        for (auto [e, w] : graph[here]) {
            int next = d + w;
            if (dist[e] > next) {
                dist[e] = next;
                q.push(e);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] < 0) {
            cout << i + 1 << "\n";
        }
    }
}