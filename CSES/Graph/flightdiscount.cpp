#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        graph[a].push_back({b, c});
    }

    using info = pair<int, pair<int, int>>;
    priority_queue<info, vector<info>, greater<info>> q;
    vector<vector<int>> dist(n, vector<int>(2, 1e18));
    q.push({0, {0, 0}});
    dist[0][0] = 0;
    dist[0][1] = 0;

    while (q.size()) {
        auto infoHere = q.top();
        q.pop();
        auto dHere = infoHere.first;
        auto disc = infoHere.second.first;
        auto here = infoHere.second.second;

        if (dist[here][disc] < dHere) continue;

        for (auto [e, w] : graph[here]) {
            if (dist[e][disc] > dHere + w) {
                dist[e][disc] = dHere + w;
                q.push({dHere + w, {disc, e}});
            }
            if (disc == 0) {
                if (dist[e][1] > dHere + (w / 2)) {
                    dist[e][1] = dHere + (w / 2);
                    q.push({dHere + (w / 2), {1, e}});
                }
            }
        }
    }

    cout << min(dist[n - 1][0], dist[n - 1][1]) << "\n";
}