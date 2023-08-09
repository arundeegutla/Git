#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

// check for int overflow.
void solve() {
    ll n = nextInt(), c = nextLong();
    vector<ll> s(n);
    for(auto& x : s)
        x = nextInt();

    auto go = [&](ll w) -> ll {
        w *= 2;
        ll tot = 0;
        for(auto x : s){
            tot += (x+w)*(x+w);
            if (tot > c) return c+1;
        }
        return tot;
    };
    
    ll lo = 0;
    ll hi = 1e10;
    ll ans = -1;
    while(lo <= hi){

        ll mid = (lo+hi)>>1;
        ll here = go(mid);
        if(here < c){
            lo = mid + 1;
        } else if(here > c) {
            hi = mid;
        } else {
            ans = mid;
            break;
        }
    }
    
    cout << ans << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}