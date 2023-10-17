#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll n, l, h;
    cin >> n >> l >> h;
    vector<ll> daily(n);
    for(auto& x : daily) cin >> x;

    vector<ll> psum = daily;
    for(int i = 1; i < n; i++)
        psum[i] += psum[i-1];

    ll minn = 1e10;
    ll maxx = -1e10;
    for(ll segSize = l; segSize <= h; segSize++){

        for(ll startDay = 1; startDay <= segSize; startDay++){

            ll profits = psum[startDay-1] > 0;
            // if(segSize == 3) {
            //     cout << startDay << " " << psum[startDay-1] << " ";
            // }
            for(ll at = startDay; at < n; at += segSize) {
                // if(segSize == 3) {
                //     cout << psum[min(n-1, at + segSize - 1)] - psum[max(0LL, at - 1)] << " ";
                // }
                profits += (psum[min(n-1, at + segSize - 1)] - psum[max(0LL, at - 1)]) > 0;
            }
            // if(segSize == 3)
            //     cout << "\n";
                
            minn = min(minn, profits);
            maxx = max(maxx, profits);
        }   

    }

    cout << minn << " " << maxx << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve(); return 0;
}