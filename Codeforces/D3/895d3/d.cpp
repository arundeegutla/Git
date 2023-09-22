#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)


void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    ll divXY = n/(lcm(x, y));
    ll divX = (n/x) - divXY;
    ll divY = (n/y) - divXY;


    // cout << divX << " " << divY << "\n";

    ll xOnly = (n*(n+1))/2;
    xOnly -= ((n-divX)*(n-divX+1))/2;
    ll yOnly = (divY*(divY+1))/2;

    cout << xOnly - yOnly << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}