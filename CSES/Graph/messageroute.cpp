#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll> dist(n, 1e18);
    vector<ll> best(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);

    while (q.size()) {
        int here = q.front();
        q.pop();
        auto d = dist[here];
        for (auto e : graph[here]) {
            if (dist[e] > d + 1) {
                dist[e] = d + 1;
                best[e] = here;
                q.push(e);
            }
        }
    }

    if (dist[n - 1] == 1e18) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    int at = n - 1;
    while (at != -1) {
        path.push_back(at + 1);
        at = best[at];
    }
    reverse(path.begin(), path.end());

    cout << dist[n - 1] + 1 << "\n";
    for (auto x : path) {
        cout << x << " ";
    }
    cout << "\n";
}