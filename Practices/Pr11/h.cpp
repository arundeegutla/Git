#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;
const int maxn=1e6+10;
const int mod = 1e9+7;
typedef long long ll;


ll Pow_mod(ll a,ll n) {
    ll res=1;
    while(n){
        if(n&1)
            res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

ll fac[maxn];
void init(){
    fac[0]=1;
    for (int i=1;i<maxn;i++) 
        fac[i] = fac[i-1] *i % mod;
}

ll C(ll n,ll m){
    return  fac[n]* Pow_mod(fac[n-m] * fac[m] % mod, mod-2) % mod;
}
int main(){
    init();
    ll n,x,y;
    cin>>n>>x>>y;

    ll t = n/max(x,y);
    ll ans=0;
    for (int i=1;i<=t;i++){
        if(n-i*x+i-1<i-1||n-i*y+i-1<i-1)
            continue;
        ans += C(n-i*x+i-1,i-1) * C(n-i*y+i-1,i-1) %mod;
        ans %= mod;
       // cout<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}