#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
 
void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> prices(n);
    vector<ll> pages(n);
    for(auto& x : prices) cin >> x;
    for(auto& x : pages) cin >> x;
 
    vector<vector<ll>> dp(n+1, vector<ll>(x+1));

    auto go = [&](int at, int money, auto&& go) -> ll {
        for(int at = n-1; at >= 0; at--){
            for(int money = x; money >= 0; money--){
                ll take = (money - prices[at] >= 0) ? (dp[at+1][money-prices[at]] + pages[at]) : -1e10;
                ll leave = dp[at+1][money];
                dp[at][money] = max(take, leave);
            }
        }
        return dp[at][money];
    };
 
    cout << go(0, x, go) << "\n";
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}