#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll

struct Dinic {
    struct Edge {
        ll to, rev, c, oc;
    };
    int n, s, t;
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int nodes) : n(nodes), s(n++), t(n++), lvl(n), ptr(n), q(n), adj(n) {}

    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, (int)adj[b].size(), c, c});
        adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int i = ptr[v]; i < adj[v].size(); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc() {
        ll flow = 0;
        q[0] = s;
        for (int L = 0; L < 31; L++)
            do {
                lvl = ptr = vi(n);
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
            } while (lvl[t]);

        return flow;
    }
};

signed main() {
    int n, m, t;
    cin >> n >> m >> t;
    t++;
    vector<string> grid(n);
    for (auto& x : grid) cin >> x;
    int D[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};

    auto getId = [&](int row, int col, int time) -> int {
        return time * (n * m) + (row * m + col);
    };

    Dinic dinic(n * m * t);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#')
                continue;

            for (auto d : D) {
                int nR = i + d[0];
                int nC = j + d[1];
                if (nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;
                for (int time = 0; time + 1 < t; time++)
                    dinic.addEdge(getId(i, j, time), getId(nR, nC, time + 1), 1);
            }

            if (grid[i][j] == 'P')
                dinic.addEdge(dinic.s, getId(i, j, 0), 1);
            for (int time = 0; time < t; time++) {
                if (grid[i][j] == 'E') {
                    dinic.addEdge(getId(i, j, time), dinic.t, 1);
                }
            }
        }
    }

    cout << dinic.calc() << "\n";
}