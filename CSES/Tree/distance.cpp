#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    graph[0].push_back(1);

    vector<vector<int>> tree(n + 1);
    auto reroot = [&](int at, int p, auto&& self) -> void {
        for (auto& e : graph[at]) {
            if (e != p) {
                self(e, at, self);
                tree[at].push_back(e);
            }
        }
    };
    reroot(0, -1, reroot);

    vector<vector<int>> dp(n + 1, vector<int>(20, 0));
    vector<long long> depth(n + 1, -1e9);

    auto dfs = [&](int a, auto&& dfs) -> void {
        for (auto& b : tree[a]) {
            if (depth[b] != -1e9) continue;
            depth[b] = depth[a] + 1;
            dp[b][0] = a;
            for (int i = 1; i < 20; i++)
                dp[b][i] = dp[dp[b][i - 1]][i - 1];
            dfs(b, dfs);
        }
    };
    depth[0] = -1;
    dfs(0, dfs);

    auto lca = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 19; i >= 0; i--)
            if ((1 << i) & diff)
                u = dp[u][i];
        if (u == v) return u;
        for (int i = 19; i >= 0; i--) {
            if (dp[u][i] != dp[v][i]) {
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        return dp[u][0];
    };

    while (q--) {
        int a, b;
        cin >> a >> b;
        int ancestor = lca(a, b);
        long long dist = (depth[a] + depth[b]) - (2LL * depth[ancestor]);
        cout << dist << "\n";
    }
}