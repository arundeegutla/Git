#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int nextInt(){int a; cin >> a; return a;}
ll nextLong(){ll a; cin >> a; return a;}
string next(){string a; cin >> a; return a;}
#define all(x) begin(x), end(x)

void solve() {
    ll n = nextInt(), k = nextInt();
    vector<ll> arr(n);
    for(auto& x : arr) x = nextInt();

    // Checks if MAX is possible.
    auto can = [&](ll MAX) {

        // go thru all indices and try to make it max.
        // MAX: 5? Can i make descending in K moves.
        // 5 4 3 2 1

        for(int i = 0; i < n; i++){
            ll make = MAX;
            ll myK = 0;
            for(int j = i; j < n; j++){
                // no need to change further.
                if(arr[j] >= make) break;
                myK += make - arr[j];
                make--;
                // Cannot update last element.
                if(j == n-1) myK += k;
                if(myK > k) break;
            }
            if(myK <= k) return true;
        }

        return false;

    };

    ll lo = *(max_element(all(arr)));
    ll hi = lo + k;
    ll ans = lo;
    while(lo <= hi){
        ll mid = (lo+hi) >> 1;
        if(can(mid))
            lo = (ans = mid) + 1;
        else 
            hi = mid - 1;
    }

    cout << ans << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n = nextInt();
    while(n--) solve();
}