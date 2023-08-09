#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    ll oo = 1e18;
    int k = nextInt();

    vector<ll> cost(n);
    for(auto& x : cost) x = nextLong();

    for(int i = 0; i < k; i++)
        cost[nextInt()-1] = 0;

    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++){
        int m = nextInt();
        while(m--)
            graph[i].push_back(nextInt()-1);
    }

    vector<ll> dist(n, oo);
    auto dfs = [&](int at, auto&& dfs) -> ll {
        if(!graph[at].size()) return cost[at];
        if(dist[at] != oo) return dist[at];

        ll sum = !graph[at].size() ? oo : 0;
        for(auto e : graph[at]) 
            sum += dfs(e, dfs);

        return dist[at] = min(cost[at], sum);
    };

    for(int i = 0; i < n; i++)
        cout << dfs(i, dfs) << " ";
    cout << "\n";
    


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}