#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
#define int ll

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

signed main() {
    int n;
    cin >> n;
    vector<vector<ll>> graph(n);
    for (auto& arr : graph) {
        int x;
        cin >> x;
        x--;
        arr.push_back(x);
    }

    auto [numComps, compId] = SCC(graph);

    // for (auto x : compId) cout << x << " ";
    // cout << "\n";

    vector<vector<int>> compGraph(numComps);
    vector<int> incoming(numComps);
    for (int i = 0; i < n; i++) {
        int comp = compId[i];
        int toComp = compId[graph[i][0]];
        if (toComp != comp) {
            compGraph[toComp].push_back(comp);
            incoming[comp]++;
        }
    }
    ll MOD = 1e9 + 7;

    function<ll(int)> dfs = [&](int at) -> ll {
        ll count = 1;
        for (auto& e : compGraph[at]) {
            count *= dfs(e);
            count %= MOD;
        }
        count += 1;
        count %= MOD;
        return count;
    };

    ll tot = 1;
    for (int i = 0; i < numComps; i++) {
        if (incoming[i] == 0) {
            tot *= dfs(i);
            tot %= MOD;
        }
    }

    tot -= 1;
    if (tot < 0) tot += MOD;
    tot %= MOD;

    cout << tot << "\n";
}