#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define int ll
// check for int overflow.
void solve() {
    int n = nextInt(), q = nextInt();
    vector<ll> maxh(n);
    vector<ll> sum(n);
    ll s = 0;
    int m = 0;
    for(int i = 0; i < n; i++){
        int x = nextInt();
        m = max(m, x);
        s += x;
        maxh[i] = m;
        sum[i] = s;
    }

    while(q--){
        int k = nextInt();
        int lo = 0;
        int hi = n-1;
        int ans = -1;
        while(lo <= hi){
            int mid = (lo+hi) >> 1;
            if(maxh[mid] <= k)
                lo = (ans = mid) + 1;
            else 
                hi = mid - 1;
        }
        cout << (ans == -1 ? 0 : sum[ans]) << " ";
    }

    cout << "\n";

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}