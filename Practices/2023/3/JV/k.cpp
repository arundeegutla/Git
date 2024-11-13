#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    vector<int> perm(n);
    for(auto& x : perm){
        cin >> x;
        x--;
    } 

    vector<vector<int>> dp(n, vector<int>(20, 0));
    vector<int> depth(n, -1);
    auto dfs = [&](int a, auto && dfs) -> void {
        for(auto b : graph[a]){
            if(depth[b] != -1) continue;
            depth[b] = depth[a] + 1;
            dp[b][0] = a;
            for(int i = 1; i < 20; i++)
                dp[b][i] = dp[dp[b][i-1]][i-1];
            dfs(b, dfs);
        }
    };
    depth[0] = 0;
    dfs(0, dfs);
    auto lca = [&](int u, int v) -> int {
        if(depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for(int i = 19; i >= 0; i--)
            if((1<<i) & diff) 
                u = dp[u][i];
        if(u == v) return u;
        for(int i = 19; i >= 0; i--){
            if(dp[u][i] != dp[v][i]){
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        return dp[u][0];
    };


    for(int i = 0; i+1 < n; i++){
        int from = perm[i];
        int to = perm[i+1];
        int ancestor = lca(from, to);

        // get root to from + root to To - unnessary
        int tot = depth[from] + depth[to] - (2*(depth[ancestor]));

        if(tot > 3) {
            cout << 0 << "\n";
            return;
        }
    }

    cout << 1 << "\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}