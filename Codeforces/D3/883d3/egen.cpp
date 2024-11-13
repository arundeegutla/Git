#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll n = nextLong();
    for(ll power = 2; power <= 30; power++){
        ll lo = 2;
        ll hi = 1000;
        while(lo <= hi){
            ll mid = (lo+hi)/2;
            ll ans = (1-((ll)pow(mid, power+1)))/(1-mid);
            if(ans > n)
                hi = mid + 1;
            else if (ans < n)
                lo = mid - 1;
            else {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}