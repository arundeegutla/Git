#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

void solve(){
    int MAX = (int)1e5;
    int MOD = (int)1e9 + 7;
    auto power = [&](ll x, ll y) -> ll {
        ll res = 1;
        x %= MOD;
        while(y>0){
            if(y%2){
                res *= x;
                res %= MOD;
            }
            y >>= 1;
            x *= x;
            x %= MOD;
        }
        return res;
    };   

    vector<ll> cat(MAX+1);
    cat[0] = 1;
    for(ll i = 1; i<=MAX; i++){
        cat[i] = cat[i-1];
        cat[i] *= (4*i-2);
        cat[i] %= MOD;
        cat[i] *= power(i+1, MOD - 2);
        cat[i] %= MOD;
    }

    cout << cat[nextInt()] << "\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}