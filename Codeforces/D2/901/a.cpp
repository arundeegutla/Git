#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    ll a, b, n;
    cin >> a >> b >> n;

    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;
    sort(all(arr));

    int i = 0;
    ll tot = b-1;
    ll cur = 1;
    while(i < n) {
        cur += arr[i++];
        while(i < n && cur+arr[i] <= a)
            cur += arr[i++];

        cur = min(cur, a);
        tot += cur - 1;
        cur = 1;
    }
    tot += cur;

    cout << tot << "\n";

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}