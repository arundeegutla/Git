#include <bits/stdc++.h>
using namespace std;
#define ll long long
int nextInt(){int a; cin >> a; return a;}

void solve(){
    int n = nextInt();
    int k = nextInt();
    ll MOD = (int)1e9 + 7;
    vector<ll> arr(n);
    for(auto& x : arr) x = nextInt();
    sort(arr.begin(), arr.end());

    vector<ll> fac(n+1);
    fac[0] = 1;
    for(ll i = 1; i <= n; i++)
        fac[i] = (fac[i-1]*i) % MOD;

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

    auto choose = [&](int x, int r) -> ll {
        if (x < r) return 0;
        if (r == 0) return 1;
        ll ans = fac[x];
        ans *= power(fac[r], MOD - 2);
        ans %= MOD;
        ans *= power(fac[x-r], MOD - 2);
        ans %= MOD;
        return ans;
    };  

    

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += (choose(i, k-1) * arr[i]) % MOD;
        sum %= MOD;
    }
    cout << sum << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
