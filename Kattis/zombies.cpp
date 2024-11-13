#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll inf = (ll)1 << 60;

struct Dinic {
    struct edge {
        ll a, b, cap, flow;
    };
    ll n, s, t;
    vi d, ptr, q;
    vector<edge> e;
    vvi g;
    Dinic(int nodes) : n(nodes), s(n++), t(n++), d(n), ptr(n), q(n), g(n) {}
    void addEdge(ll a, ll b, ll cap) {
        edge e1 = {a, b, cap, 0}, e2 = {b, a, 0, 0};
        g[a].push_back(e.size());
        e.push_back(e1);
        g[b].push_back(e.size());
        e.push_back(e2);
    }
    bool bfs() {
        ll qh = 0, qt = 0;
        q[qt++] = s;
        d = vi(n, -1);
        d[s] = 0;
        while (qh < qt && d[t] == -1) {
            ll v = q[qh++];
            for (int i = 0; i < g[v].size(); ++i) {
                ll id = g[v][i],
                   to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }
    ll dfs(ll v, ll flow) {
        if (!flow) return 0;
        if (v == t) return flow;
        for (; ptr[v] < (ll)g[v].size(); ++ptr[v]) {
            ll id = g[v][ptr[v]];
            ll to = e[id].b;
            if (d[to] != d[v] + 1) continue;
            ll pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    ll getflow() {
        ll flow = 0;
        while (true) {
            if (!bfs()) break;
            ptr = vi(n);
            while (ll pushed = dfs(s, inf)) flow += pushed;
        }
        return flow;
    }
};

void solve() {
    int n;
    cin >> n;
    int starting, groupSize, timeSteps;
    cin >> starting >> groupSize >> timeSteps;
    timeSteps++;
    starting--;
    int m;
    cin >> m;
    vector<int> isMedical(n);
    for (int i = 0; i < m; i++) {
        int at;
        cin >> at;
        at--;
        isMedical[at] = true;
    }

    auto getId = [&](int node, int time) -> int {
        return time * n + node;
    };

    Dinic dinic(timeSteps * n + 10);

    for (int i = 0; i < n; i++) {
        for (int time = 0; time + 1 < timeSteps; time++) {
            dinic.addEdge(getId(i, time), getId(i, time + 1), 1e9);
        }
        if (isMedical[i])
            dinic.addEdge(getId(i, timeSteps - 1), dinic.t, 1e9);
    }

    int r;
    cin >> r;
    for (int i = 0; i < r; i++) {
        int a, b, p, t;
        cin >> a >> b >> p >> t;
        a--, b--;
        for (int time = 0; time < timeSteps; time++) {
            if (time + t >= timeSteps) break;
            dinic.addEdge(getId(a, time), getId(b, time + t), p);
        }
    }

    dinic.addEdge(dinic.s, getId(starting, 0), groupSize);
    cout << dinic.getflow() << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}