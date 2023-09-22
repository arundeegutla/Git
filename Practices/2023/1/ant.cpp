#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU{
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


int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        int hills, tunnels;
        cin >> hills >> tunnels;

        vector<pair<ll, pair<int, int>>> edges;
        while(tunnels--){
            int from, to, d;
            cin >> from >> to >> d;

            edges.push_back({d, {from, to}});
            edges.push_back({d, {to, from}});
        }

        sort(begin(edges), end(edges));

        int used = 0;
        DSU dsu(hills+10);
        int tot = 0;
        for(auto e : edges)
            if(dsu.join(e.second.first, e.second.second)){
                tot += e.first;
                used++;
            }


        cout << "Campus #" << i << ": ";
        if(used!=hills-1){
            cout << "I'm a programmer, not a miracle worker!" << "\n";
        } else {
            cout << tot << "\n";
        }


    }
}