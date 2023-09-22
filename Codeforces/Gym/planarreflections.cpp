#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using D1 = vector<ll>;
using D2 = vector<D1>;
using D3 = vector<D2>;
#define all(x) begin(x), end(x)

void solve() {
    int n, k; 
    cin >> n >> k;


    D3 memo(n+1, D2(k+1, D1(2, -1)));
    int MOD = 1e9 + 7;

    auto go = [&](int at, int num, bool right, auto && go) -> ll {
        
        if(num == 0) return 0;
        if(at == -1 && !right) return 1;
        if(at == n && right) return 1;

        auto& ans = memo[at][num][right];
        if(ans!=-1) return ans;

        ll count = 0;
        
        if(right) {
            count += go(at + 1, num, true, go);
            count %= MOD;
            count += go(at - 1, num - 1, false, go);
            count %= MOD;
        } else {
            count += go(at - 1, num, false, go);
            count %= MOD;
            count += go(at + 1, num - 1, true, go);
            count %= MOD;
        }

        return ans = count;

    };

    cout << go(0, k, true, go) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}