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

    vector<ll> b;
    int prev = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; b.size() < n && j < arr[i] - prev; j++){
            b.push_back(i+1);
        }
        prev = arr[i];
    }

    // for(auto x : b) cout << x << " ";
    // cout<< "\n";

    cout << (arr == b ? "YES" : "NO") << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    while(n--) solve();
}