#include <bits/stdc++.h>
using namespace std;
#define int long long

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

    using info = pair<int, int>;
    priority_queue<info, vector<info>, greater<info>> pq;
    vector<int> dist(n, 1e18);
    pq.push({0, 0});
    dist[0] = 0;

    while (pq.size()) {
        auto [dhere, here] = pq.top();
        pq.pop();
        if (dist[here] < dhere) continue;
        for (auto [e, d] : graph[here]) {
            if (dist[e] > dhere + d) {
                dist[e] = dhere + d;
                pq.push({dhere + d, e});
            }
        }
    }

    for (auto c : dist)
        cout << c << " ";
    cout << "\n";
}