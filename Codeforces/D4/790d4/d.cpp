#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    int n = nextInt(), m = nextInt();
    vector<vector<ll>> grid(n, vector<ll>(m));
    for(auto& x : grid)
        for(auto& c : x)
            c = nextInt();

    unordered_map<int, int> pos;
    unordered_map<int, int> neg;
    

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            pos[i+j] += grid[i][j];
            neg[i-j] += grid[i][j];
        }
    }

    ll maxx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            maxx = max(maxx, pos[i+j] + neg[i-j] - grid[i][j]);


    cout << maxx << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}