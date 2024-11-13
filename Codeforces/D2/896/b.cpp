#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--;
    b--;

    vector<pair<ll, ll>> cities(n);
    for(auto& x : cities){
        cin >> x.first;
        cin >> x.second;
    }

    ll direct = abs(cities[a].first-cities[b].first) + abs(cities[a].second-cities[b].second);
    ll aMinn = 1e10;
    ll bMinn = 1e10;
    for(int i = 0; i < k; i++){
        ll distToA = abs(cities[a].first-cities[i].first) + abs(cities[a].second-cities[i].second);
        ll distToB = abs(cities[b].first-cities[i].first) + abs(cities[b].second-cities[i].second);
        aMinn = min(aMinn, distToA);
        bMinn = min(bMinn, distToB);
    }

    ll ans = min(aMinn + bMinn, direct);
    
    assert(ans < 1e10);
    cout << ans << "\n";
 

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}