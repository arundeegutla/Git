#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    ll prod = 1;
    int zeroCount = 0;
    for(auto& x : arr){
        cin >> x;
        zeroCount += x == 0;
        if(x!=0) prod *= x;
    }

    if(zeroCount){
        if(zeroCount == 1) {
            cout << prod << "\n";
            return;
        } else {
            cout << 0 << "\n";
            return;
        }
    }

    ll maxx = prod;
    for(auto x : arr){
        ll here = prod/x;
        here *= 1+x;
        maxx = max(maxx, here);
    }

    cout << maxx << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}