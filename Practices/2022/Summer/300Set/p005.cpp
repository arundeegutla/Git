#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

void solve(){
    int n = nextInt(), MOD = nextInt(), queries = nextInt();
    vector<vector<int>> graph(n, vector<int>());

    for(int i = 0; i+1 < n; i++){
        int from = nextInt() - 1;
        int to = nextInt() - 1;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<int> num(n);
    for(auto& x : num) x = nextInt();

    vector<int> depth(n, -1);
    vector<string> rootTo(n);
    vector<vector<int>> dp(n, vector<int>(20, 0));

    auto dfs = [&](int a, auto && dfs) -> void {
        for(auto b : graph[a]){
            if(depth[b] != -1) continue;
            depth[b] = depth[a] + 1;
            rootTo[b] = rootTo[a] + to_string(num[b]);
            dp[b][0] = a;
            for(int i = 1; i < 20; i++)
                dp[b][i] = dp[dp[b][i-1]][i-1];
            dfs(b, dfs);
        }    
    };
    depth[0] = 0;
    rootTo[0] = to_string(num[0]);
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

    while(queries--){
        int s = nextInt() - 1, e = nextInt() - 1;
        int ancestor = lca(s, e);

        string storoot = rootTo[s];
        string roottoe = rootTo[e];
        int ansDiff = depth[ancestor] - depth[0];

        ll llAns = 0;
        for(int i = storoot.size()-1; i >= ansDiff; i--){
            int numHere = storoot[i]-'0';
            llAns *= 10;
            llAns %= MOD;
            llAns += numHere;
            llAns %= MOD;
        }
        for(int i = ansDiff+1; i < roottoe.size(); i++){
            int numHere = roottoe[i]-'0';
            llAns *= 10;
            llAns %= MOD;
            llAns += numHere;
            llAns %= MOD;
        }

        cout << llAns << "\n";
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}