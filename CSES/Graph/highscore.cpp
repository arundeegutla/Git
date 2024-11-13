#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges;
    vector<vector<int>> graph(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back({{a, b}, -c});
        graph[a].push_back(b);
    }

    vector<bool> pathToEnd(n);
    vector<bool> seen(n);
    function<bool(int)> go = [&](int at) -> bool {
        if (at == n - 1) return pathToEnd[at] = true;
        if (seen[at]) return false;
        seen[at] = true;
        bool reach = false;
        for (auto x : graph[at]) reach |= go(x);
        return pathToEnd[at] = reach;
    };
    go(0);

    vector<int> dist(n, 1e18);
    dist[0] = 0;

    // O(V*E)
    for (int i = 0; i < n; i++) {
        for (auto [e, w] : edges)
            dist[e.second] = min(dist[e.second], dist[e.first] + w);
    }

    bool changed = false;
    for (int i = 0; i < n; i++)
        for (auto [e, w] : edges) {
            if (dist[e.second] > dist[e.first] + w) {
                dist[e.second] = dist[e.first] + w;
                changed |= pathToEnd[e.first] || pathToEnd[e.second];
            }
        }

    if (changed) {
        cout << -1 << "\n";
        return 0;
    }

    cout << -dist[n - 1] << "\n";
}