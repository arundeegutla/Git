#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace SCCKosaraju {
vector<vector<int>> adj, radj;
vector<int> todo, comp;
vector<bool> vis;
void dfs1(int x) {
    vis[x] = 1;
    for (int y : adj[x])
        if (!vis[y]) dfs1(y);
    todo.push_back(x);
}
void dfs2(int x, int i) {
    comp[x] = i;
    for (int y : radj[x])
        if (comp[y] == -1) dfs2(y, i);
}
vector<int> scc(vector<vector<int>>& _adj) {
    adj = _adj;
    int time = 0, n = adj.size();
    comp.resize(n, -1), radj.resize(n), vis.resize(n);
    for (int x = 0; x < n; x++)
        for (int y : adj[x]) radj[y].push_back(x);
    for (int x = 0; x < n; x++)
        if (!vis[x]) dfs1(x);
    reverse(todo.begin(), todo.end());
    for (int x : todo)
        if (comp[x] == -1) dfs2(x, time++);
    return comp;
}
};  // namespace SCCKosaraju

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graphW(n);
    vector<vector<int>> graph(n);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        graphW[a].push_back({b, c});
        graph[a].push_back(b);
    }

    auto compId = SCCKosaraju::scc(graph);

    vector<bool> seen(n);
    vector<int> path(n, -1);

    auto bellman = [&](int at) -> int {
        // O(V*E)
        vector<int> dist(n, 1e18);
        path.clear();
        path.resize(n, -1);
        vector<pair<pair<int, int>, int>> edgesHere;
        for (int i = 0; i < n; i++) {
            if (compId[at] != compId[i]) continue;
            for (auto [e, c] : graphW[i]) {
                if (compId[at] != compId[e]) continue;
                edgesHere.push_back({{i, e}, c});
            }
        }

        dist[at] = 0;
        path[at] = -2;
        for (int i = 0; i < n; i++)
            for (auto [e, w] : edgesHere) {
                if (dist[e.first] + w < dist[e.second]) {
                    dist[e.second] = min(dist[e.second], dist[e.first] + w);
                    path[e.second] = e.first;
                }
            }

        // Neg cycles
        for (auto [e, w] : edgesHere)
            if (dist[e.first] + w < dist[e.second]) {
                // Neg cycle detected
                path[e.second] = e.first;
                return e.second;
            }
        return -1;
    };

    unordered_set<int> done;
    for (int i = 0; i < n; i++) {
        if (!done.count(compId[i])) {
            done.insert(compId[i]);
            auto here = bellman(i);
            if (here != -1) {
                cout << "YES\n";

                for (auto e : path) {
                    cout << e << "\n";
                }

                // while (here != -2) {
                //     cout << here + 1 << " ";
                //     here = path[here];
                // }

                cout << "\n";
                return 0;
            }
        }
    }

    cout << "NO\n";
}