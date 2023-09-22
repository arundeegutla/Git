#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
#define all(x) begin(x), end(x)

void solve() {
    int n; cin >> n;
    vector<ll> arr(n);
    for(auto& x : arr) cin >> x;
    string s; cin >> s;

    ll xorZero = 0;
    ll xorOne = 0;
    vector<ll> prefixXOR(n+1);
    for(int i = 0; i < n; i++){
        prefixXOR[i+1] = prefixXOR[i] ^ arr[i];
        if(s[i] == '0'){
            xorZero ^= arr[i];
        } else {
            xorOne ^= arr[i];
        }
    }
    
    int c; cin >> c;
    while(c--){
        int q; cin >> q;
        if(q == 1){
            int l, r; cin >> l >> r;
            ll cur = prefixXOR[r] ^ prefixXOR[l-1];
            xorZero ^= cur;
            xorOne ^= cur;
        } else {
            int v; cin >> v;
            cout << (v ? xorOne : xorZero) << " ";
        }
    }
    
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}