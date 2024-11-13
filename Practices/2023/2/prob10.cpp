#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, w;
    cin >> n >> w;
    vector<ll> weigts(n);
    vector<ll> sat(n);
    for(auto& x : weigts) cin >> x;
    for(auto& x : sat) cin >> x;

    vvvi memo(n, vvi(w+1, vi(200, -1)));

    auto go = [&](int at, int curW, int prev, auto&& go) -> ll {
        if(curW < 0) return -1e10;
        if(at == n) return 0;

        auto& ans = memo[at][curW][prev];
        if(ans!=-1){
            // cout << "memo!\n";
            return ans;
        } 
        ll maxx = prev == 0 ? go(at+1, curW, 0, go) : -1e10;
        
        for(int i = prev+1; i < 200 && curW - (weigts[at] * i) >= 0; i++){
            maxx = max(maxx, go(at+1, curW - (weigts[at] * i), i, go) + (sat[at] * i));
        }
        return ans = maxx;
    };

    cout << go(0, w, 0, go) << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}