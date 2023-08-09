 #include <bits/stdc++.h>
 using namespace std;
 using ll = long long;
 int nextInt(){int a; cin >> a; return a;}
 ll nextLong(){ll a; cin >> a; return a;}
 string next(){string a; cin >> a; return a;}
 
 void solve() {
    int n = nextInt();
    vector<vector<int>> tree(n, vector<int>());
    for(int i = 0; i < n-1; i++){
        int from = nextInt()-1;
        int to = nextInt() - 1;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    vector<bool> visit(n);
    vector<vector<int>> newtree(n, vector<int>());
    auto dfs = [&](int at, auto && dfs) -> void {
        for(auto e : tree[at]){
            if(visit[e]) continue;
            visit[e] = true;
            newtree[at].push_back(e);
            dfs(e, dfs);
        }
    };
    visit[0] = true;
    dfs(0, dfs);

    vector<ll> dp(n);
    auto go = [&](int at, auto && go) -> ll {
        if(newtree[at].size() == 0) return dp[at] = 1;
        for(auto e : newtree[at])
            dp[at] += go(e, go);
        return dp[at];
    };

    go(0, go);

    int q = nextInt();
    while(q--){
        cout << dp[nextInt() - 1] * dp[nextInt() - 1] << '\n';
    }

 }
 
 int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
 }