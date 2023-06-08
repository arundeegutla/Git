#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
int nextInt() {int a;cin >> a;return a;}
ll nextLong(){ll a; cin >> a;return a;}
string next(){string a; cin >> a;return a;}

void solve() {
    ll x = nextLong();

    auto numFactors = [](ll num, ll power) -> bool {
        unordered_set<ll> hset;
        for(ll i = 1; i*i <= num; i++) {
            if(num%i == 0) {
                hset.insert(i);
                hset.insert(num/i);
            }
            if(hset.size() > power) return false;
        }
        hset.size();
        return hset.size() == power;
    };

    for(int fn = 400; fn >= 1; fn--){
        ld n = pow(x, (ld)(1.0/fn));
        n = round(n*1000)/1000;
        if(n != (int)n) continue;
        if((ll)(pow(n, fn)) != x) continue;
        if(numFactors((int)n, fn)){
            cout << (int)n << "\n";
            return;
        }
    }

    cout << "-1" << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}