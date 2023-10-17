#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

void solve() {
    int n = nextInt();
    int r = nextInt() - 1, c = nextInt() - 1;
    // n*n
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            grid[i][j] = nextInt();

    vector<vector<ll>> memo(n, vector<ll>(n, -1));
    auto go = [&](int x, int y, auto && go) -> ll {
        ll& ans = memo[x][y];
        if(ans != -1) return ans;
        ll total = 0;
        for(int v = -1; v <= 1; v+=2){
            int nR = x + v;
            if(nR < 0 || nR >= n) continue;
            for(int i = 0; i < n; i++) {
                int nC = i;
                if(abs(nC - y) <= 1 || nC < 0 || nC >= n || grid[nR][nC] <= grid[x][y]) continue;
                total = max(total, go(nR, nC, go));       
            }
        }
        for(int v = -1; v <= 1; v+=2){
            int nC = y + v;
            if(nC < 0 || nC >= n) continue;
            for(int i = 0; i < n; i++) {
                int nR = i;
                if(abs(nR - x) <= 1 || nR < 0 || nR >= n || grid[nR][nC] <= grid[x][y]) continue;
                total = max(total, go(nR, nC, go)); 
            }
        }   
        return ans = total + 1;
    };

    cout << go(r, c, go) <<  '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}