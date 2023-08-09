#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define int ll
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}

void solve() {
    ll n = nextLong();
    bool found = false;
    for(ll power = 2; power <= 100; power++){
        ll lo = 2;
        ll hi = 1e10;
        while(lo <= hi){
            ll mid = (lo+hi)/2;
            double ans = (1-(pow(mid, power+1))) / (1-mid);

            if(abs(ans - n) <= 1e-4){
                cout << "YES\n";
                found = true;
                break;
            } 
            
            if(ans > n)
                hi = mid - 1;
            else if (ans < n)
                lo = mid + 1;

        }

        if(found) break;
    }
    if(!found)
        cout << "NO\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}