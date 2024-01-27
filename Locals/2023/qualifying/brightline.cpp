#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> graph(n);
    while (m--) {
        ll s, e, a;
        s--, e--;
        char t;
        cin >> s >> e >> t >> a;
        if (t == 'r') a *= -1LL;
        graph[s].push_back({a, e});
    }

    queue<int> q;
    q.push(0);
    vector<ll> dist(n, 1e18);
    dist[0] = 0;

    while (q.size()) {
        int here = q.front();
        q.pop();
        int d = dist[here];
        for (auto [w, e] : graph[here]) {
            int next = d + w;
            if (dist[e] > next) {
                dist[e] = next;
                q.push(e);
            }
        }
    }

    int count = 0;
    for (auto x : dist) {
        count += x < 0;
    }

    cout << count << "\n";
}