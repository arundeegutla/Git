#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define int ll
// check for int overflow.
void solve() {
    ll n = nextInt(), c = nextInt();
    vector<pair<ll, ll>> cost;
    for(int i = 1; i <= n; i++){
        ll x = nextInt();
        cost.push_back({min(x+i, x+n+1-i), x+i});
    }
    sort(cost.begin(), cost.end());


    for(int i = 1; i < n; i++)
        cost[i].first += cost[i-1].first;


    int maxx = 0;
    for(int i = 0; i < n; i++){
        if(cost[i].second > c) continue;
        int lo = 0;
        int hi = n-1;
        int ans = 0;

        while(lo <= hi) {
            int mid = (lo+hi) >> 1;
            ll sum = cost[mid].first + cost[i].second;
            if(mid >= i) {
                sum -= cost[i].first;
                if(i-1 >= 0) sum += cost[i-1].first;
            }
            if(sum <= c){
                lo = mid + 1;
                ans = mid + (mid < i);
            } 
            else hi = mid - 1;
        }

        maxx = max(maxx, ans+1);
    }

    cout << maxx << "\n";

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}
