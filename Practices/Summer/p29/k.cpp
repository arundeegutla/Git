#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    vector<ll> installation(n);
    for(auto& x : installation) x = nextInt();
    vector<vector<int>> graph(n);
    for(int i = 0; i < n - 1; i++){
        int from = nextInt()-1, to = nextInt()-1;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<ll> t(n);
    vector<bool> seen(n);
    auto dfs = [&](int at, auto&& dfs) -> ll {
        seen[at] = true;
        vector<ll> distances;
        for(auto e : graph[at])
            if(!seen[e])
                distances.push_back(dfs(e, dfs));
        sort(distances.begin(), distances.end(), greater<int>());
        ll cur = 0;
        ll time = 0;
        for(auto x : distances){
            cur++;
            if(x+cur > time) time = x+cur;
            cur++;
        }
        return t[at] = max(max(cur, time), installation[at]);
    };

    cout << dfs(0, dfs) + installation[0] << "\n";
    // for(auto x : t)
    //     cout << x << " ";
    // cout << "\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}