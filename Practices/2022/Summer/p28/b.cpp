#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Edge = pair<ll, pair<int, int>>;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define oo (ll)1e18
class DSU{
public:
    vector<int> parent;
    vector<vector<int>> children;
    vector<ll> tot;
    vector<stack<pair<int, ll>>> updates;
    DSU(int n) {
        children.resize(n); parent.resize(n);tot.resize(n);updates.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            children[i].push_back(i);
        }
    }
    int find(int node) {
        return node == parent[node] ? node : parent[node] = find(parent[node]);
    }
    bool join(int a, int b, ll c){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        int sizea = children[a].size();
        int sizeb = children[b].size();
        if(sizea < sizeb){
            swap(a, b);
            swap(sizea, sizeb);
        }


        for(auto child : children[b]){
            children[a].push_back(child);
            tot[child] += c*sizea;

            for(auto i : children[child]) {
                auto u = updates[i];
                if(u.size() == 0) continue;
                int at = 0;
                int end = u[0].first - 1;
                ll sum = u[0].second;
                while(end >= 0){
                    if(at+1<u.size() && end == u[at+1].first - 1){
                        sum += u[at].second;
                        at++;
                    }
                    ds.tot[ds.children[i][end]] += sum;
                    end--;
                }
            }
                tot[child] += c*sizeb;
        }
        parent[b] = a;
        return true;
    }
};


void solve() {
    int n = nextInt();
    int m = nextInt();
    vector<Edge> edges;
    for(int i = 0; i < m; i++) {
        int from = nextInt()-1, to = nextInt()-1, c = nextInt();
        edges.push_back({c, {from, to}});
    }
    sort(edges.begin(), edges.end());
    vector<Edge> mst;
    DSU ds(n);
    for(auto e : edges) {
        int from = e.second.first, to = e.second.second, c = e.first;
        if(ds.join(from, to, c))
            mst.push_back(e);
    }
    for(auto x : ds.tot)
        cout << x << "\n";
}

int main(){
    freopen("road.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n = nextInt();
    for(int i = 1; i <= n; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}