#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> fruits(n);
    vector<ll> height(n);
    for(auto& x : fruits) cin >> x;
    for(auto& x : height) cin >> x;

    auto go = [&](ll len) -> ll {
        int start = 0;
        ll minn = 1e10;
        while(start+len-1 < n){
            bool cantGo = false;
            ll f = 0;

            for(int i = start; i+1 < start+len; i++) {
                if(height[i] % height[i+1] != 0){
                    start = i+1;
                    cantGo = true;
                    break;
                }
                f += fruits[i];
            }

            if(cantGo) continue;

            f += fruits[start+len-1];

            minn = min(f, minn);


            if(start + len >= n) {
                break;
            }
            for(int i = start + len; i < n; i++) {
                if(height[i-1] % height[i] != 0){
                    start = i;
                    break;
                }
                f -= fruits[start];
                f += fruits[i];
                start++;
                minn = min(f, minn);
            }

        }

        // cout << len << " " << minn << "\n";
        return minn;

    };

    ll lo = 2;
    ll hi = n;
    ll ans = -1;
    while(lo <= hi){
        ll mid = (lo+hi) >> 1;
        ll count = go(mid);
        if(count <= k) {
            lo = (ans = mid) + 1;
        } else {
            hi = mid - 1;
        }

    }

    if(ans == -1) {
        ll minn = *(min_element(all(fruits)));
        cout << (minn <= k) << "\n";
        return;
    }

    cout << ans << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}