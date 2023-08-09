#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define oo (ll)1e18
void solve() {
    int n = nextInt(), s = nextInt(), t = nextInt();
    vector<vector<ll>> grid(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            grid[i][j] = nextInt();
    
    vector<ll> dist(n, oo);
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(q.size()){
        int here = q.front(); q.pop();
        ll d = dist[here];
        for(int i = 0; i < n; i++){
            if(dist[i] > d + grid[here][i]) {
                dist[i] = d + grid[here][i];
                q.push(i);
            }
        }
    }
    cout << dist[t] << "\n";
}   

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}