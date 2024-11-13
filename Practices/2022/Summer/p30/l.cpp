#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define sz(x) (int) (x).size()

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
	};
	int n, s, t;
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int nodes):n(nodes), s(n++), t(n++), lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p;
                    adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc() {
		ll flow = 0;
		q[0] = s;
		for(int L = 0; L < 31; L++)
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


void solve(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto& x : grid) cin >> x;

    Dinic dinic(n+m);
    for(int i = 0; i < n; i++)
        dinic.addEdge(dinic.s, i, 1);
    for(int i = 0; i < m; i++)
        dinic.addEdge(i+n, dinic.t, 1);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
			if(grid[i][j]-'0')
            	dinic.addEdge(i, j+n, 1);

    cout << dinic.calc() << "\n";
}

signed main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}