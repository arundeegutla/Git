#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll memo[11][11][10];
int main() {
    memset(memo, -1, sizeof(memo));
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto& x : grid) cin >> x;

    string s = "YOKOHAMA";
    using ll = long long;

    function<ll(int, int, int)> go = [&](int r, int c, int at) -> ll {
        if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != s[at]) return 0;
        if(at == s.size() - 1) return 1;
        auto& ans = memo[r][c][at];
        if(ans != -1 ){
            // cout << "memo!\n";
            return ans;
        } 
        ll here = 0;
        here += go(r - 1, c, at + 1);
        here += go(r + 1, c, at + 1);
        here += go(r, c - 1, at + 1);
        here += go(r, c + 1, at + 1);

        return ans = here;
    };



    ll tot = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'Y') {
                tot += go(i, j, 0);
            }
        }
    }

    cout << tot << "\n";

}