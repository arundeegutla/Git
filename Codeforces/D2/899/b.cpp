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
    ll all = 0;
    vector<ll> sets(n);
    for(auto& val : sets){
        int m;
        cin >> m;
        while(m--){
            int x;
            cin >> x;
            val |= (1LL<<x);
            all |= (1LL<<x);
        }
    }
    
    int maxx = 0;
    // dont pick the ones with (1<<at).
    for(int at = 1; at <= 50; at++){

        ll here = 0;
        for(auto x : sets)
            if(!(x & (1LL<<at)))
                here |= x;
                
        if(here != all)
            maxx = max(maxx, (int)bitset<60>(here).count());
    }

    cout << maxx << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}