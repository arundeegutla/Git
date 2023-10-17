#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = pair<pair<int, int>, ll>;
using vi = vector<Edge>;
using vvi = vector<vi>;

void solve(){
    ll oo = 1e10;
    int n, m; cin >> n >> m;

    vi edges;
    while(m--){
        ll from, to, c; cin >> from >> to >> c;
        edges.push_back({{from, to}, c});
    }

    vector<ll> dist(n, oo);
    dist[0] = 0;

    // can it do in three iterations
    for(int i = 0; i < 3; i++){
        for(int i = 1; i < n; i++)
            for(auto [e, w] : edges)
                dist[e.second] = min(dist[e.second], dist[e.first] + w);

        // Neg cycles?
        for(auto [e, w] : edges)
            if(dist[e.first] + w < dist[e.second]){
                dist[e.second] = -oo;
                dist[e.first] = -oo;
            }
    }

    // for(auto x : dist)
    //     cout << x << " ";
    // cout << "\n";
    cout << (dist[0] < 0 ? "possible" : "not possible") << "\n";
    
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}