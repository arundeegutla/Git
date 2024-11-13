#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using Edge = pair<ll, pair<int, int>>;

class DSU{
public:
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n+1); parent.resize(n+1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int node) {
        return node == parent[node] ? node : parent[node] = find(parent[node]);
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};


void solve(){
    int n, m; cin >> n >> m;
    vector<Edge> edges;

    while(m--){
        int from, to, d; cin >> from >> to >> d;
        edges.push_back({d, {from, to}});
    }
    sort(edges.begin(), edges.end(), greater<Edge>());
    ll cost = 0;
    ll maxx = 0;
    DSU dsu(n+1);
    for(auto [w, e] : edges){
        if(!dsu.join(e.first, e.second)){
            cost += w;
            maxx = max(maxx, w);
        }
    }
    cout << cost << " " << maxx << "\n";    
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}