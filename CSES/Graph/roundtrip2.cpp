#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
struct SCC {
    int num_sccs = 0;
    vi scc_id;
    SCC(vvi& adj) : scc_id(adj.size(), -1) {
        int n = adj.size(), timer = 1;
        vi tin(n), st;
        st.reserve(n);
        auto dfs = [&](auto&& self, int u) -> ll {
            ll low = tin[u] = timer++, siz = st.size();
            st.push_back(u);
            for (int v : adj[u])
                if (scc_id[v] < 0) low = min(low, tin[v] ? tin[v] : self(self, v));
            if (tin[u] == low) {
                for (int i = siz; i < st.size(); i++) scc_id[st[i]] = num_sccs;
                st.resize(siz);
                num_sccs++;
            }
            return low;
        };
        for (int i = 0; i < n; i++)
            if (!tin[i]) dfs(dfs, i);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vvi adj(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }
    auto [numComps, compId] = SCC(adj);

    int start = -1;
    int id = -1;
    vi compSize(numComps);
    for (int i = 0; i < n; i++) {
        int x = compId[i];
        compSize[x]++;
        if (compSize[x] > 1) {
            id = x;
            start = i;
        }
    }
    if (start == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vi ans;
    vi seen(n);
    function<void(int)> go = [&](int at) -> void {
        if (seen[at]) return;
        };
}