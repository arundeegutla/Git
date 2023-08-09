#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt();
    int m = nextInt();
    ll oo = 1e10;
    vector<vector<pair<int, int>>> graph(n);
    while(m--){
        int a = nextInt()-1, b = nextInt()-1, d = nextInt();
        graph[a].push_back({b, d});
        // need to add the rev edge to changeup the startinpos.
        graph[b].push_back({a, -d});
    }

    vector<ll> dist(n, oo);
    for(int i = 0; i < n; i++){
        if(dist[i]!=oo) continue;
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(q.size()){
            int here = q.front(); q.pop();
            ll d = dist[here];
            for(auto [e, w] : graph[here]){
                if(dist[e] != oo && dist[e] != d+w){
                    cout << "NO\n";
                    return;
                }

                if(dist[e] == oo){
                    dist[e] = d + w;
                    q.push(e);
                }
            }
        }
    }

    cout << "YES\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}