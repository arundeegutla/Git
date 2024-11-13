#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    ll n, m, k; 
    cin >> n >> m >> k;

    vector<ll> a(n);
    vector<ll> b(m);

    for(auto& x : a) cin >> x;
    for(auto& x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    // odd swap
    if (a[0] < b[m-1]) {
        int temp = a[0];
        a[0] = b[m-1];
        b[m-1] = temp;
    }

    sort(all(a));
    sort(all(b));

    // even swap
    if (k%2 == 0 && b[0] < a[n-1]) {
        int temp = b[0];
        b[0] = a[n-1];
        a[n-1] = temp;
    }

    cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}