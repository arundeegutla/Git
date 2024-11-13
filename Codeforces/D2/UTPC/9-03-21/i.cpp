#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    int n = nextInt();
    int m = nextInt();
    ll oo = 1e10;
    vector<string> grid(n);
    for(auto& x : grid) x = next();

    auto go = [&]() -> vector<vector<ll>> {
        vector<vector<ll>> dist(n, vector<ll>(m, oo));
        int myr = nextInt(), myc = nextInt();

        int D[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({myr, myc});
        dist[myr][myc] = 0LL;
        while(q.size()){
            auto [r, c] = q.front(); q.pop();
            ll myD = dist[r][c];
            for(auto d : D){
                int nR = r+d[0];
                int nC = c+d[1];
                if(nR < 0 || nR >= n || nC < 0 || nC >= m || grid[nR][nC] == '#') continue;
                if(myD + 1 < dist[nR][nC]) {
                    dist[nR][nC] = myD + 1;
                    q.push({nR, nC});
                }
            }
        }
        return dist;
    };

    vector<vector<ll>> a1 = go();
    vector<vector<ll>> a2 = go();
    vector<vector<ll>> b1 = go();
    vector<vector<ll>> b2 = go();


    ll ans = 1e18;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a1[i][j] >= oo || a2[i][j] >= oo || b1[i][j] >= oo || b2[i][j] >= oo) continue;
            ll tot = a1[i][j] + a2[i][j] + b1[i][j] + b2[i][j];
            ans = min(ans, tot);
        }
    }

    if(ans >= 1e10) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << ans << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}