#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ll n, m, t, d;
    cin >> n >> m >> t >> d;

    set<int> gasStations;
    gasStations.insert(0);
    gasStations.insert(n - 1);
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        x--;
        gasStations.insert(x);
    }

    vector<vector<ll>> graph(n, vector<ll>(n, 1e18));
    while (m--) {
        ll from, to, k;
        cin >> from >> to >> k;
        from--, to--;
        graph[from][to] = k;
        graph[to][from] = k;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    vector<ll> dist(n, 1e18);
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (q.size()) {
        int here = q.front();
        q.pop();
        ll dis = dist[here];
        if (here == n - 1) continue;
        for (auto& station : gasStations) {
            if (graph[here][station] > d) continue;
            if (dis + graph[here][station] < dist[station]) {
                dist[station] = dis + graph[here][station];
                q.push(station);
            }
        }
    }

    if (dist[n - 1] == 1e18) {
        cout << "stuck\n";
    } else {
        cout << dist[n - 1] << "\n";
    }
}