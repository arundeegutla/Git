#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve(int n) {
    vector<vector<ll>> memo(n, vector<ll>(n, -1));

    auto go = [&](int r, int c, auto&& go) -> ll {
        if(r == n-1 && c == n-1) return 1;
        if(r >= n || c >= n || r > c+1) return 0;

        auto& ans = memo[r][c];
        if(ans!=-1) return ans;
        ll count = 0;
        count += go(r+1, c, go);
        count += go(r, c+1, go);
        return ans = count;

    };

    cout << go(0, 0, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    while(true){
        int n;
        cin >> n;
        if(!n) return 0;
        solve(n);
    }
}