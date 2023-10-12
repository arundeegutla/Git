#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    ll maxx = (k * (2 * n - k + 1)) / 2;
    ll minn = (k * (k + 1)) / 2;
    
    if (x >= minn && x <= maxx) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}